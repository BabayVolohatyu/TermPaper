#pragma once
#include <mutex>


#include "ContactBook.h"
#include "Date.h"
#include "../../UI/Headers/TimeButton.h"

class TimeManager {
    private:
    static std::mutex mutex;
    static std::chrono::time_point<std::chrono::system_clock> currentTime;
    static Contact* contactToGreet;
    TimeManager() = delete;
    public:
    static void getClosestBirthday(const std::vector<Contact*>& birthday);
    static Contact* getContact();
    static void startClockUpdateThread(TimeButton* clockButton);
};

