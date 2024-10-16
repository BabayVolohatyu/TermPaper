#include "../Headers/ConsoleManager.h"

Color ConsoleManager::standardConsoleColor = WHITE;

void ConsoleManager::selectObject(Visual& visualObject) {
    visualObject.setColor(GREEN);
}

void ConsoleManager::setColorToObject(Visual& visualObject, Color color) {
    visualObject.setColor(color);
}

void ConsoleManager::changeTextColor(Color color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void ConsoleManager::display(Visual &visualObject) {
    visualObject.print();
    changeTextColor(standardConsoleColor);
}


