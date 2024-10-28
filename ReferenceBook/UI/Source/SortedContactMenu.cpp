#include "../Headers/SortedContactMenu.h"

#include <windows.h>

#include "../../System/Headers/Contact.h"
#include "../Headers/AddContactMenu.h"
#include "../Headers/ConsoleManager.h"
#include "../../System/Headers/ContactBook.h"

SortedContactMenu::SortedContactMenu():ContactMenu{}, tagName{}{

}

std::string SortedContactMenu::getTagName() {
    return tagName;
}

Button * SortedContactMenu::getButton(int index) const {
    return sortedButtons[index].first;
}

int SortedContactMenu::getSize() const {
    return static_cast<int>(sortedButtons.size());
}

void SortedContactMenu::setTagName(const std::string &newTagName) {
    tagName = newTagName;
}

void SortedContactMenu::clear() {
    sortedButtons.clear();
}

void SortedContactMenu::print() {
    ConsoleManager::changeTextColor(currentColor);
    if(tagName.empty()&&selectedIndex<0) {
        ConsoleManager::setIgnoreInputStatus(true);
        ConsoleManager::refreshButtonBuffer();
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
        sortedButtons.clear();
        std::cout << "|Enter the name of tag, please: ";
        std::getline(std::cin, tagName);
        std::vector<Contact *> sortedContacts = ContactBook::getContactsWithTag(tagName);

        std::vector<Button*> buttons = *getInstance()->getButtons();
        for(Button *button : buttons) {
            sortedButtons.emplace_back(button, false);
        }
        for(const Contact *contact : sortedContacts) {
        }
        ConsoleManager::refreshButtonBuffer();
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
        ConsoleManager::setIgnoreInputStatus(false);
    }
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
        indexToShowEnd = std::min(offset * 2 - 1, static_cast<int>(sortedButtons.size()));
    } else {
        if (selectedIndex <= 0) {
            indexToShowStart = 0;
            indexToShowEnd = std::min(selectedIndex + offsetToShow, static_cast<int>(sortedButtons.size()));
        } else {
            indexToShowStart = std::max(selectedIndex - offsetToShow, 0);
            indexToShowEnd = std::min(selectedIndex + offsetToShow + 1, static_cast<int>(sortedButtons.size()));
        }
    }
    for (int i = indexToShowStart; i < indexToShowEnd; i++) {

        if(sortedButtons[i].second)sortedButtons[i].first->print();
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
