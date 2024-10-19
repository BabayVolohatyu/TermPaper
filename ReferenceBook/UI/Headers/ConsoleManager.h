#pragma once

#include <windows.h>

#include "Menu.h"

class ConsoleManager {
public:
    ConsoleManager();

    static void changeTextColor(Color color);

    static void hideCursor();

    static void display(const Visual &visualObject);

    static void refresh(Visual &visualObject);

    static void setColorToObject(Visual &visualObject, Color color);

    static void delay(int milliseconds);

    static void selectNext(Menu &menu);
};
