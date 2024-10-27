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
    public:
    TimeManager() = delete;
    static void getClosestBirthday(const std::vector<Contact*>& birthday);
    static Contact* getContact();
    static void startClockUpdateThread(TimeButton* clockButton);
};

