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
    // Отримуємо дескриптор консолі для виводу тексту
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Встановлюємо колір тексту
    SetConsoleTextAttribute(hConsole, static_cast<int>(color));
}

void ConsoleManager::hideCursor() {
    // Отримуємо дескриптор консолі для виводу тексту
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    // Отримуємо інформацію про курсор
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);

    // Приховуємо курсор
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void ConsoleManager::changeCursorVisibilityState() {
    // Отримуємо дескриптор консолі для вводу тексту
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;

    // Отримуємо поточний режим консолі і змінюємо його
    if (GetConsoleMode(hInput, &mode)) {
        if (mouseInputEnabled) {
            SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS | (mode & ~ENABLE_QUICK_EDIT_MODE));
        } else {
            SetConsoleMode(hInput, mode | ENABLE_QUICK_EDIT_MODE);
        }
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
    //Очищуємо буфер кнопок активуючи всі наявні не виконуючи ніяких дій з ними
    for (int key = 0; key < 256; ++key) {
        GetAsyncKeyState(key);
    }
}


void ConsoleManager::delay(unsigned milliseconds) {
    Sleep(milliseconds);
}

void ConsoleManager::selectNextButton(Menu *menu) {
    try {
        // Перевіряємо, чи обраний індекс знаходиться на останньому елементі меню
        if (Menu::getSelectedIndex() >= menu->getSize() - 1) {
            // Встановлюємо стандартний колір
            menu->getButton(Menu::getSelectedIndex())->setColor(Visual::standardColor);

            // Якщо обраний індекс знаходиться на останньому елементі, повертаємось на початок
            Menu::selectIndex(0);

            // Змінюємо колір
            menu->getButton(Menu::getSelectedIndex())->setColor(Visual::selectedColor);
        } else {
            if (Menu::getSelectedIndex() >= 0) {
                menu->getButton(Menu::getSelectedIndex())->setColor(Visual::standardColor);
            }

            // Переходимо до наступного індексу в меню
            Menu::selectIndex(Menu::getSelectedIndex() + 1);

            // Змінюємо колір кнопки
            menu->getButton(Menu::getSelectedIndex())->setColor(Visual::selectedColor);
        }
    } catch (...) {
        Menu::selectIndex(-1);
    }
}

void ConsoleManager::selectPreviousButton(Menu *menu) {
    try {
        // Перевіряємо, чи обраний індекс є першим елементом меню
        if (Menu::getSelectedIndex() == 0) {
            // Встановлюємо стандартний колір для поточної кнопки
            menu->getButton(Menu::getSelectedIndex())->setColor(Visual::standardColor);

            // Якщо це перший елемент, переходимо на останній
            Menu::selectIndex(menu->getSize() - 1);

            // Змінюємо колір
            menu->getButton(Menu::getSelectedIndex())->setColor(Visual::selectedColor);
        } else if (Menu::getSelectedIndex() == -1) {
            // Якщо індекс не обраний, переходимо на останній елемент
            Menu::selectIndex(menu->getSize() - 1);

            // Змінюємо колір
            menu->getButton(Menu::getSelectedIndex())->setColor(Visual::selectedColor);
        } else {
            // Встановлюємо стандартний колір для поточної кнопки
            menu->getButton(Menu::getSelectedIndex())->setColor(Visual::standardColor);

            // Переходимо на попередній індекс в меню
            Menu::selectIndex(Menu::getSelectedIndex() - 1);

            // Змінюємо колір
            menu->getButton(Menu::getSelectedIndex())->setColor(Visual::selectedColor);
        }
    } catch (...) {
        Menu::selectIndex(-1);
    }
}

void ConsoleManager::returnToPreviousMenu() {
    try {
        if (!menuStack.empty())Menu::selectIndex(-1);
        while (!menuStack.empty()) {
            currentMenu = menuStack.top();
            menuStack.pop();
            if (currentMenu != nullptr) {
                return;
            }
        }
    } catch (...) {
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
