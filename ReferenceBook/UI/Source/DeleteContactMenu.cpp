#include <windows.h>
#include "../Headers/DeleteContactMenu.h"

#include "../../System/Headers/Contact.h"
#include "../../System/Headers/ContactBook.h"
#include "../Headers/ConsoleManager.h"
#include "../Headers/ContactMenu.h"

DeleteContactMenu::DeleteContactMenu(): Menu{"Deleting contact", 0} {}

void DeleteContactMenu::print() {
    ConsoleManager::setIgnoreInputStatus(true);
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    std::string userInput;
    std::cout << '|' << name << '|' << std::endl;
    std::cout << '|' << "Enter the name of contact you want to delete:";
    std::getline(std::cin, userInput);
    int sizeOfBook = ContactBook::getSize();
    for(int i = 0; i < sizeOfBook ; i++) {
        if(userInput == ContactBook::getContact(i)->getName()) {
            ContactBook::erase(i);
        }
    }
    int sizeOfContactBookMenu = ContactMenu::getInstance()->getSize();
    for(int i = 0; i < sizeOfContactBookMenu ; i++) {
        if(userInput == ContactMenu::getInstance()->getButton(i)->getName()) {
            ContactMenu::getInstance()->erase(i);
        }
    }
    ConsoleManager::returnToPreviousMenu();
    ConsoleManager::clear();
    ConsoleManager::display(ConsoleManager::getCurrentMenu());
    ConsoleManager::setIgnoreInputStatus(false);
}

