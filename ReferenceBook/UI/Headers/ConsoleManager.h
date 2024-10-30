#pragma once

#include <stack>

#include "Menu.h"

class ConsoleManager {
    static std::stack<Menu *> menuStack; //стек меню
    static Menu *currentMenu; //поточне меню
    static bool ignoreInputStatus; //змінна для ігнорування основних функцій меню
    static bool mouseInputEnabled; //змінна для керування мишею

public:
    ConsoleManager() = default;

    ~ConsoleManager();

    //функція, що змінює колір тексту
    static void changeTextColor(Color color);

    //функція, що ховає каретку виводу консолі
    static void hideCursor();

    //функція, що змінює можливість зчитування миші.
    //потрібна для забезпечення нормальної діяльності програми
    static void changeCursorVisibilityState();

    //функція виводу візуального об'єкта в консоль
    static void display(Visual *visualObject);

    //функція очищення консолі
    static void clear();

    //функція, що очищує буфер натиснутих клавіш
    static void refreshButtonBuffer();

    //функція, що змінює колір візуального об'єкта
    static void setColorToObject(Visual *visualObject, Color color);

    //функція для зміни параметра ігнорування основних функцій меню
    static void setIgnoreInputStatus(bool status);

    //функція для затримки
    static void delay(unsigned milliseconds);

    //функція для вибору наступної кнопки
    static void selectNextButton(Menu *menu);

    //функція для вибору попередньої кнопки
    static void selectPreviousButton(Menu *menu);

    //функція для повернення до попереднього меню
    static void returnToPreviousMenu();

    //функція для встановлення поточного меню
    static void setCurrentMenu(Menu *menu);

    static Menu *getCurrentMenu();

    static bool getIgnoreInputStatus();

    //функія для додавання меню в стек
    static void pushMenu(Menu *menu);
};
