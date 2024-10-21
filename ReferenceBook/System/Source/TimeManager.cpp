#include <thread>
#include "../Headers/TimeManager.h"
#include "../../UI/Headers/TimeButton.h"

std::mutex TimeManager::mutex;
std::chrono::time_point<std::chrono::system_clock> TimeManager::currentTime = Date::getLocalTime();

void TimeManager::startClockUpdateThread(TimeButton *timeButton) {
    std::thread clockUpdateThread([timeButton] {
        while (true) {
            std::unique_lock uniqueLock{mutex};
            currentTime = Date::getLocalTime();
            if (timeButton) {
                timeButton->setName(Date::parseTimePointToString(currentTime));
                timeButton->setPreciseTime(Date::getLocalTimeOfTheDayAsString());
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });
    clockUpdateThread.detach();
}
