#pragma once

#include "Menu.h"

class ConsoleManager {
    static Menu *currentMenu;
public:
    ConsoleManager() = default;

    ~ConsoleManager();

    static void changeTextColor(Color color);

    static void hideCursor();

    static void display(const Visual &visualObject);

    static void clear();

    static void setColorToObject(Visual &visualObject, Color color);

    static void delay(int milliseconds);

    static void selectNextButton(Menu &menu);

    static void selectPreviousButton(Menu &menu);

    static void setCurrentMenu(Menu *menu);

    static Menu* getCurrentMenu();


};
