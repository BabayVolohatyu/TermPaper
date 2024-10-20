#include "../Headers/Menu.h"
#include "../Headers/ConsoleManager.h"

int Menu::selectedIndex = -1;

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
    if(button->getWidth() > this->getWidth()) {
        std::string newName = button->getName().substr(0,
             this->getWidth() - (button->getWidth()-button->getName().size())/2 );
        button->setName(newName);
        button->setWidth(this->getWidth());
    }else if(button->getWidth() < this->getWidth()) {
        button->setWidth(this->getWidth());
    }
    this->buttons.emplace_back(button);
}

Button* Menu::getButton(int index) {
    return buttons[index];
}

int Menu::getSelectedIndex() const {
    return selectedIndex;
}

int Menu::getSize() const {
    return buttons.size();
}

void Menu::selectIndex(int index) {
    selectedIndex = index;
}


void Menu::print() const {
    ConsoleManager::changeTextColor(currentColor);
    std::cout << std::endl;
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
    ConsoleManager::changeTextColor(currentColor);
    std::cout << '|';
    for (int i = 0; i < offset; i++) {
        std::cout << '-';
    }
    std::cout << name;
    for (int i = 0; i < offset; i++) {
        std::cout << '-';
    }
    std::cout << '|' << std::endl;
}
