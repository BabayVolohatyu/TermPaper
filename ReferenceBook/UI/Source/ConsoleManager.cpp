#include <windows.h>

#include "../Headers/ConsoleManager.h"

Menu *ConsoleManager::currentMenu = nullptr;
std::stack<Menu *> ConsoleManager::menuStack{};
bool ConsoleManager::ignoreInputStatus = false;

ConsoleManager::~ConsoleManager() {
    if (currentMenu != nullptr) {
        delete currentMenu;
        currentMenu = nullptr;
    }

    while (!menuStack.empty()) {
        if (menuStack.top() != nullptr) {
            delete menuStack.top();
        }
        menuStack.pop();
    }
}


void ConsoleManager::setColorToObject(Visual *visualObject, Color color) {
    visualObject->setColor(color);
}

void ConsoleManager::setIgnoreInputStatus(bool status) {
    ignoreInputStatus = status;
}

bool ConsoleManager::getIgnoreInputStatus() {
    return ignoreInputStatus;
}

void ConsoleManager::changeTextColor(Color color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<int>(color));
}

void ConsoleManager::hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void ConsoleManager::display(const Visual *visualObject) {
    visualObject->print();
}

void ConsoleManager::clear() {
    system("cls");
}

void ConsoleManager::refreshButtonBuffer() {
    for (int key = 0; key < 256; ++key) {
        GetAsyncKeyState(key);
    }
}


void ConsoleManager::delay(int milliseconds) {
    Sleep(milliseconds);
}

void ConsoleManager::selectNextButton(Menu *menu) {
    if (menu->getSelectedIndex() >= menu->getSize() - 1) {
        menu->getButton(menu->getSelectedIndex())->setColor(Visual::standardColor);
        menu->selectIndex(0);
        menu->getButton(menu->getSelectedIndex())->setColor(Visual::selectedColor);
    } else {
        if (menu->getSelectedIndex() >= 0) menu->getButton(menu->getSelectedIndex())->setColor(Visual::standardColor);
        menu->selectIndex(menu->getSelectedIndex() + 1);
        menu->getButton(menu->getSelectedIndex())->setColor(Visual::selectedColor);
    }
}

void ConsoleManager::selectPreviousButton(Menu *menu) {
    if (menu->getSelectedIndex() == 0) {
        menu->getButton(menu->getSelectedIndex())->setColor(Visual::standardColor);
        menu->selectIndex(menu->getSize() - 1);
        menu->getButton(menu->getSelectedIndex())->setColor(Visual::selectedColor);
    } else if (menu->getSelectedIndex() == -1) {
        menu->selectIndex(menu->getSize() - 1);
        menu->getButton(menu->getSelectedIndex())->setColor(Visual::selectedColor);
    } else {
        menu->getButton(menu->getSelectedIndex())->setColor(Visual::standardColor);
        menu->selectIndex(menu->getSelectedIndex() - 1);
        menu->getButton(menu->getSelectedIndex())->setColor(Visual::selectedColor);
    }
}

void ConsoleManager::returnToPreviousMenu() {
    if (!menuStack.empty()) {
        currentMenu = menuStack.top();
        menuStack.pop();
    }
}

void ConsoleManager::setCurrentMenu(Menu *menu) {
    currentMenu = menu;
}

Menu *ConsoleManager::getCurrentMenu() {
    return currentMenu;
}

void ConsoleManager::pushMenu(Menu *menu) {
    menuStack.push(menu);
}
