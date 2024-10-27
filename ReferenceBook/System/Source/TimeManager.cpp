#include <thread>
#include "../Headers/TimeManager.h"
#include "../../UI/Headers/TimeButton.h"
#include "../Headers/Contact.h"

std::mutex TimeManager::mutex;
std::chrono::time_point<std::chrono::system_clock> TimeManager::currentTime = Date::getLocalTime();
Contact* TimeManager::contactToGreet = nullptr;

void TimeManager::getClosestBirthday(const std::vector<Contact*>& contacts) {
    std::chrono::year_month_day  currentTime = std::chrono::floor<std::chrono::days>(Date::getLocalTime());
    if(!ContactBook::getContacts().empty()) {
        contactToGreet = *std::min_element(contacts.begin(), contacts.end(),
[&](const Contact* c1, const Contact* c2) {

std::chrono::year_month_day date1 = c1->getDateOfBirth().getDate();
std::chrono::year_month_day date2 = c2->getDateOfBirth().getDate();

std::chrono::month_day md1(date1.month(), date1.day());
std::chrono::month_day md2(date2.month(), date2.day());
std::chrono::month_day currentMD(currentTime.month(), currentTime.day());
if(md1>currentMD&&md2<currentMD) return true;
if(md2>currentMD&&md1<currentMD) return false;
if (md1 == md2) {
return (date1.year() == date2.year()) ? false : date1.year() < date2.year();
}

return md1 < md2;
});
    }

}

Contact* TimeManager::getContact() {
    return contactToGreet;
}

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
