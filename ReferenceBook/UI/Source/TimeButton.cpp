#include "../Headers/TimeButton.h"
#include "../Headers/ConsoleManager.h"
TimeButton::TimeButton(const std::string &name, int height, int width) :
Button{name, height, width}{}

void TimeButton::print() {
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

    int offset = (width - name.size()) / 2;
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

    offset = (width - preciseTime.size()) / 2;
    if (offset == 0) offset++;
    std::cout << '|';
    for (int i = 0; i < offset; i++) {
        std::cout << ' ';
    }
    std::cout << preciseTime;
    for (int i = 0; i < offset; i++) {
        std::cout << ' ';
    }
    std::cout << '|';
    std::cout << std::endl;

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
}

void TimeButton::setPreciseTime(const std::string &preciseTime) {
    this->preciseTime = preciseTime;
}

