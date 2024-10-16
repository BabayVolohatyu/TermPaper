#pragma once

#include <windows.h>

#include "../Color.h"
#include "../Headers/Visual.h"

class ConsoleManager {
    private:
    static Color standardConsoleColor;
    public:

    ConsoleManager();
    static void selectObject(Visual& visualObject);

    static void changeTextColor(Color color);

    static void display(Visual& object);

    static void setColorToObject(Visual& visualObject, Color color);
};
