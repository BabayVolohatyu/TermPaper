#include "../Headers/Button.h"
#include "../Headers/ConsoleManager.h"

Button::Button(const std::string &name, int height, int width)
    : Object{name, height, width}, menuItRefersTo{nullptr} {
}

Button::~Button() {
    if(menuItRefersTo != nullptr) {
        delete menuItRefersTo;
        menuItRefersTo = nullptr;
    }
}

void Button::setMenuToRefer(Menu *menuToRefer) {
    menuItRefersTo = menuToRefer;
}

Menu *Button::getMenuItRefersTo() {
    return menuItRefersTo;
}


void Button::print() {
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
    ConsoleManager::changeTextColor(standardColor);
}
