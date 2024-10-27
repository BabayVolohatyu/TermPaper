#include "../Headers/ContactMenu.h"

#include <algorithm>
#include <windows.h>

#include "../../System/Headers/Contact.h"
#include "../Headers/AddContactMenu.h"
#include "../Headers/ConsoleManager.h"
#include "../../System/Headers/ContactBook.h"

ContactMenu *ContactMenu::instance = nullptr;
int ContactMenu::offsetToShow = 3;

ContactMenu::ContactMenu(const std::string &name, int width)
    : Menu{name, width} {
}

ContactMenu::~ContactMenu() {
    instance = nullptr;
}

ContactMenu *ContactMenu::getInstance(const std::string &name, int width) {
    if (!instance) {
        instance = new ContactMenu{name, width};
        return instance;
    } else return instance;
}

void ContactMenu::insert(Button *newButton) {
    if (getInstance()->buttons.empty()) getInstance()->buttons.emplace_back(newButton);
    else {
        std::string newButtonName = newButton->getName();
        std::transform(newButtonName.begin(),
                       newButtonName.end(),
                       newButtonName.begin(),
                       tolower);
        std::string buttonToCompareName;
        std::vector<Button *>::iterator it = getInstance()->buttons.begin();
        for (; it < getInstance()->buttons.end(); it++) {
            buttonToCompareName = (*it)->getName();
            std::transform(buttonToCompareName.begin(),
                           buttonToCompareName.end(),
                           buttonToCompareName.begin(),
                           tolower);
            if (newButtonName <= buttonToCompareName) {
                getInstance()->buttons.insert(it, newButton);
                return;
            }
        }
        getInstance()->buttons.emplace_back(newButton);
    }
}

void ContactMenu::deleteInstance() {
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}

void ContactMenu::setOffset(int offset) {
    offsetToShow = offset;
}

int ContactMenu::getOffset() {
    return offsetToShow;
}

void ContactMenu::print() {
    ConsoleManager::changeTextColor(currentColor);
    std::cout << std::endl;
    std::cout << '|';
    int offset = (width - static_cast<int>(name.size())) / 2;
    for (int i = 0; i < offset; i++) {
        std::cout << '-';
    }
    std::cout << name;
    for (int i = 0; i < offset; i++) {
        std::cout << '-';
    }
    std::cout << '|' << std::endl;

    int indexToShowStart, indexToShowEnd;
    if (selectedIndex < offsetToShow) {
        indexToShowStart = 0;
        indexToShowEnd = std::min(offset * 2 - 1, static_cast<int>(buttons.size()));
    } else {
        if (selectedIndex <= 0) {
            indexToShowStart = 0;
            indexToShowEnd = std::min(selectedIndex + offsetToShow, static_cast<int>(buttons.size()));
        } else {
            indexToShowStart = std::max(selectedIndex - offsetToShow, 0);
            indexToShowEnd = std::min(selectedIndex + offsetToShow + 1, static_cast<int>(buttons.size()));
        }
    }
    if(static_cast<int>(buttons.size()) > 0) {
    for (int i = indexToShowStart; i < indexToShowEnd; i++) {
        buttons[i]->print();
    }
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

