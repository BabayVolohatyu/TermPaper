#pragma once

#include <stack>

#include "Menu.h"

class ConsoleManager {
    static std::stack<Menu*> menuStack;
    static Menu *currentMenu;
    static bool ignoreInputStatus;
public:
    ConsoleManager() = default;

    ~ConsoleManager();

    static void changeTextColor(Color color);

    static void hideCursor();

    static void display(const Visual *visualObject);

    static void clear();

    static void refreshButtonBuffer();

    static void setColorToObject(Visual *visualObject, Color color);

    static void setIgnoreInputStatus(bool status);

    static void delay(int milliseconds);

    static void selectNextButton(Menu *menu);

    static void selectPreviousButton(Menu *menu);

    static void returnToPreviousMenu();

    static void setCurrentMenu(Menu *menu);

    static Menu* getCurrentMenu();

    static bool getIgnoreInputStatus();

    static void pushMenu(Menu *menu);


};
