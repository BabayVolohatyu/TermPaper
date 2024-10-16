#include <utility>

#include "../Headers/Menu.h"
#include "../Headers/ConsoleManager.h"

Menu::Menu(const std::string &name, int width)
    : Object{name, 1, width}, buttons{}{
}
Menu::~Menu() {
    for (Button* button : buttons) {
        delete button;
    }
    buttons.clear();
}

void Menu::emplace_back(Button* button) {
    button->setWidth(this->width);
    this->buttons.push_back(button);
}

Button* Menu::getButton(int index) {
    return buttons[index];
}

void Menu::print() const {
    ConsoleManager::changeTextColor(color);
    std::cout << '|';
    int offset = (width - name.size()) / 2;
    for (int i = 0; i < offset; i++) {
        std::cout << '-';
    }
    std::cout << name;
    for (int i = 0; i < offset; i++) {
        std::cout << '-';
    }
    std::cout << '|' << std::endl;
    for (Button *button: buttons) {
        button->print();
    }
    ConsoleManager::changeTextColor(color);
    std::cout << '|';
    for (int i = 0; i < offset; i++) {
        std::cout << '-';
    }
    std::cout << name;
    for (int i = 0; i < offset; i++) {
        std::cout << '-';
    }
    std::cout << '|';
}
