#include <windows.h>

#include "../Headers/ConsoleManager.h"

Menu *ConsoleManager::currentMenu = nullptr;
std::stack<Menu *> ConsoleManager::menuStack{};
bool ConsoleManager::ignoreInputStatus = false;
bool ConsoleManager::mouseInputEnabled = true;

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

void ConsoleManager::changeCursorVisibilityState() {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;

    // Отримуємо поточний режим консолі
    if (GetConsoleMode(hInput, &mode)) {
        if (mouseInputEnabled) {
            // Вимикаємо обробку миші
            SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS | (mode & ~ENABLE_QUICK_EDIT_MODE));
            std::cout << "Події миші заблоковано." << std::endl;
        } else {
            // Увімкнути обробку миші
            SetConsoleMode(hInput, mode | ENABLE_QUICK_EDIT_MODE);
            std::cout << "Події миші увімкнено." << std::endl;
        }
        // Змінюємо стан
        mouseInputEnabled = !mouseInputEnabled;
    }
}

void ConsoleManager::display(Visual *visualObject) {
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
    try {
        if (Menu::getSelectedIndex() >= menu->getSize() - 1) {
            menu->getButton(Menu::getSelectedIndex())->setColor(Visual::standardColor);
            Menu::selectIndex(0);
            menu->getButton(Menu::getSelectedIndex())->setColor(Visual::selectedColor);
        } else {
            if (Menu::getSelectedIndex() >= 0) menu->getButton(Menu::getSelectedIndex())->setColor(Visual::standardColor);
            Menu::selectIndex(Menu::getSelectedIndex() + 1);
            menu->getButton(Menu::getSelectedIndex())->setColor(Visual::selectedColor);
        }
    }catch (...) {
        Menu::selectIndex(-1);
    }
}

void ConsoleManager::selectPreviousButton(Menu *menu) {
    try {
        if (Menu::getSelectedIndex() == 0) {
            menu->getButton(Menu::getSelectedIndex())->setColor(Visual::standardColor);
            Menu::selectIndex(menu->getSize() - 1);
            menu->getButton(Menu::getSelectedIndex())->setColor(Visual::selectedColor);
        } else if (Menu::getSelectedIndex() == -1) {
            Menu::selectIndex(menu->getSize() - 1);
            menu->getButton(Menu::getSelectedIndex())->setColor(Visual::selectedColor);
        } else {
            menu->getButton(Menu::getSelectedIndex())->setColor(Visual::standardColor);
            Menu::selectIndex(Menu::getSelectedIndex() - 1);
            menu->getButton(Menu::getSelectedIndex())->setColor(Visual::selectedColor);
        }
    }catch (...) {
        Menu::selectIndex(-1);
    }
}

void ConsoleManager::returnToPreviousMenu() {
    try {
        while (!menuStack.empty()) {
            currentMenu = menuStack.top();
            menuStack.pop();
            if (currentMenu != nullptr) {
                return;
        }
        }
    }catch (...) {
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
