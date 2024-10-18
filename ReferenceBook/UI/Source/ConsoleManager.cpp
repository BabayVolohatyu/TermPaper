#include "../Headers/ConsoleManager.h"



void ConsoleManager::setColorToObject(Visual& visualObject, Color color) {
    visualObject.setColor(color);
}

void ConsoleManager::changeTextColor(Color color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void ConsoleManager::display(Visual &visualObject) {
    visualObject.print();
}

void ConsoleManager::delay(int milliseconds) {
    Sleep(milliseconds);
}

void ConsoleManager::selectNext(Menu &menu){
    if(menu.getSelectedIndex() >= menu.getSize()-1) {
        menu.getButton(menu.getSelectedIndex())->setColor(Visual::standardColor);
        menu.selectIndex(0);
        menu.getButton(menu.getSelectedIndex())->setColor(Visual::selectedColor);
    }
    else {
        if(menu.getSelectedIndex() >=0 ) menu.getButton(menu.getSelectedIndex())->setColor(Visual::standardColor);
        menu.selectIndex(menu.getSelectedIndex()+1);
        menu.getButton(menu.getSelectedIndex())->setColor(Visual::selectedColor);
    }
}



