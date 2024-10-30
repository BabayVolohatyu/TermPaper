#include "../Headers/Button.h"
#include "../Headers/ConsoleManager.h"

Button::Button(const std::string &name, int height, int width)
    : Object{name, height, width}, menuItRefersTo{nullptr} {
}

Button::~Button() {
    if (menuItRefersTo != nullptr) {
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
    // Змінюємо колір тексту до поточного кольору кнопки
    ConsoleManager::changeTextColor(currentColor);

    // Виводимо верхній край кнопки
    std::cout << ' ';
    for (int i = 0; i < width; i++) {
        std::cout << '~';
    }
    std::cout << std::endl;

    // Виводимо верхню порожню частину кнопки
    for (int i = 0; i < height / 2; i++) {
        std::cout << '|';
        for (int j = 0; j < width; j++) {
            std::cout << ' ';
        }
        std::cout << '|';
        std::cout << std::endl;
    }

    // Визначаємо відступ для розміщення назви кнопки посередині
    int offset = (width - static_cast<int>(name.size())) / 2;
    if (offset == 0) offset++; // Встановлюємо мінімальний відступ

    // Виводимо рядок з назвою кнопки
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

    // Виводимо нижню порожню частину кнопки
    for (int i = 0; i < height / 2; i++) {
        std::cout << '|';
        for (int j = 0; j < width; j++) {
            std::cout << ' ';
        }
        std::cout << '|';
        std::cout << std::endl;
    }

    // Виводимо нижній край кнопки
    std::cout << ' ';
    for (int i = 0; i < width; i++) {
        std::cout << '~';
    }
    std::cout << std::endl;

    // Повертаємо колір тексту до стандартного
    ConsoleManager::changeTextColor(standardColor);
}
