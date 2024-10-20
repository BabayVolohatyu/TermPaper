#include "../Headers/ContactMenu.h"
#include "../Headers/ConsoleManager.h"

ContactMenu::ContactMenu(const std::string &name, int width)
:Menu{name, width} {}

void ContactMenu::setOffset(int offset) {
    offsetToShow = offset;
}

int ContactMenu::getOffset() {
    return offsetToShow;
}

void ContactMenu::print() const {
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

    int indexToShowStart, indexToShowEnd;
    if (selectedIndex < offsetToShow) {
        indexToShowStart = 0;
        indexToShowEnd = std::min(offset * 2 -1, static_cast<int>(buttons.size()));
    } else {
        if (selectedIndex <= 0) {
            indexToShowStart = 0;
            indexToShowEnd = std::min(selectedIndex + offsetToShow, static_cast<int>(buttons.size()));
        } else {
            indexToShowStart = std::max(selectedIndex - offsetToShow, 0);
            indexToShowEnd = std::min(selectedIndex + offsetToShow+1, static_cast<int>(buttons.size()));
        }
    }
    for (int i = indexToShowStart; i < indexToShowEnd; i++) {
        buttons[i]->print();
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
