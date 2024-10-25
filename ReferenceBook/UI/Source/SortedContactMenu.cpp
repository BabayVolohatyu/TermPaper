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

void SortedContactMenu::setTagName(const std::string &tagName) {
    this->tagName = tagName;
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
        std::cout << "|Enter the name of tag, please: ";
        std::string input;
        std::cin.ignore();
        std::getline(std::cin, input);
        tagName = input;
        std::cout << "Current tagName: " << tagName << std::endl;
        std::vector<Contact *> sortedContacts = ContactBook::getContactsWithTag(tagName);
        std::vector<Button*> buttons = *getInstance()->getButtons();
        for(Button *button : buttons) {
            std::vector<std::pair<Button*, bool>>::iterator it = std::find_if(sortedButtons.begin(), sortedButtons.end(),
        [button](const std::pair<Button*, bool>& p) {
            return p.first == button;
        });
            if (it == sortedButtons.end()) {
                sortedButtons.emplace_back(button, false);
            }
        }
        for(const Contact *contact : sortedContacts) {
            for (std::pair<Button*, bool> &button : sortedButtons) {
                if(button.first->getName() == contact->getName() && button.second == false) {
                    button.second = true;
                }
            }
        }
        ConsoleManager::refreshButtonBuffer();
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
        ConsoleManager::setIgnoreInputStatus(false);
    }
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
