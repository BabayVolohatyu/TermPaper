#include "../Headers/Menu.h"
#include "../Headers/ConsoleManager.h"

int Menu::selectedIndex = -1;

Menu::Menu(const std::string &name, int width)
    : Object{name, 1, width}, buttons{}{
}
Menu::~Menu() {
    if(!buttons.empty()) {
        for (Button* button : buttons) {
            if(button != nullptr) {
            delete button;
                button = nullptr;
            }
        }
    }
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

void Menu::erase(int id) {
    std::vector<Button *>::iterator it = buttons.begin();
    std::advance(it, id);
    try {
        buttons.erase(it);
    } catch (...) {
        return;
    }
}

Button* Menu::getButton(int index) const{
    return buttons[index];
}

int Menu::getSelectedIndex() {
    return selectedIndex;
}

int Menu::getSize() const {
    return buttons.size();
}

void Menu::selectIndex(int index) {
    selectedIndex = index;
}


void Menu::print() {
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
