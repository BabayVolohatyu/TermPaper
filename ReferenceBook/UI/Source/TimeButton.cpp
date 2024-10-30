#include "../Headers/TimeButton.h"

#include "../../System/Headers/Contact.h"
#include "../../System/Headers/TimeManager.h"
#include "../Headers/ConsoleManager.h"
TimeButton::TimeButton(const std::string &name, int height, int width) :
Button{name, height, width}{}

void TimeButton::print() {
    //Виводимо верхню частину
    ConsoleManager::changeTextColor(currentColor);
    std::cout << ' ';
    for (int i = 0; i < width; i++) {
        std::cout << '~';
    }
    std::cout << std::endl;
    for (int i = 0; i < height / 2; i++) {
        std::cout << '|';
        for (int j = 0; j < width; j++) {
            std::cout << ' ';
        }
        std::cout << '|';
        std::cout << std::endl;
    }

    int offset = (width - static_cast<int>(name.size())) / 2;
    if (offset == 0) offset++;
    std::cout << '|';
    for (int i = 0; i < offset; i++) {
        std::cout << ' ';
    }
    std::cout << name;
    for (int i = 0; i < offset; i++) {
        std::cout << ' ';
    }
    std::cout << '|';
    std::cout << std::endl;

    offset = (width - static_cast<int>(preciseTime.size())) / 2;
    if (offset == 0) offset++;
    std::cout << '|';
    for (int i = 0; i < offset; i++) {
        std::cout << ' ';
    }
    // Виводимо час
    std::cout << preciseTime;
    for (int i = 0; i < offset; i++) {
        std::cout << ' ';
    }
    std::cout << '|';
    std::cout << std::endl;
    // Виводимо нижню частину
    for (int i = 0; i < height / 2; i++) {
        std::cout << '|';
        for (int j = 0; j < width; j++) {
            std::cout << ' ';
        }
        std::cout << '|';
        std::cout << std::endl;
    }

    std::cout << ' ';
    for (int i = 0; i < width; i++) {
        std::cout << '~';
    }
    std::cout << std::endl;
    // Виводимо нагадування про найближчий день народження серед контактів
   if(!ContactBook::getContacts().empty()) {
       std::cout <<"|You should call " << TimeManager::getContact()->getName()
    << ", their birthday on " << Date::parseDateToString(TimeManager::getContact()->getDateOfBirth());
   }else std::cout <<"|You have no one to call ";
}

void TimeButton::setPreciseTime(const std::string &newPreciseTime) {
    preciseTime = newPreciseTime;
}

