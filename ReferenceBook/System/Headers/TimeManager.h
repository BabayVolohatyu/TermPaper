#pragma once
#include <mutex>


#include "Date.h"
#include "../../UI/Headers/TimeButton.h"

class TimeManager {
    private:
    static std::mutex mutex;
    static std::chrono::time_point<std::chrono::system_clock> currentTime;
    TimeManager() = delete;
    public:

    static void startClockUpdateThread(TimeButton* clockButton);
};

