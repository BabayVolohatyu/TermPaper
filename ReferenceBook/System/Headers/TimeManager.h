#pragma once
#include <mutex>


#include "ContactBook.h"
#include "Date.h"
#include "../../UI/Headers/TimeButton.h"

class TimeManager {
private:
    static std::mutex mutex; //мютекс
    static std::chrono::time_point<std::chrono::system_clock> currentTime; //поточний час
    static Contact *contactToGreet; //контакт, якого потрібно привітати

public:
    TimeManager() = delete;

    //функція, що вираховує найближчий день народження
    static void getClosestBirthday(const std::vector<Contact *> &birthday);

    static Contact *getContact();

    //функція, що запускає окремий потік для рахування часу
    static void startClockUpdateThread(TimeButton *clockButton);
};
