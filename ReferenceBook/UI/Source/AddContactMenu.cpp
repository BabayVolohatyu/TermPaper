#include "../Headers/AddContactMenu.h"

#include "../../System/Headers/ContactBook.h"
#include "../../System/Headers/Contact.h"
#include "../Headers/ConsoleManager.h"
#include "../Headers/ContactInfoMenu.h"
#include "../Headers/ContactMenu.h"

AddContactMenu::AddContactMenu(): Menu{"New contact", 0} {}

void AddContactMenu::print() const {
    ConsoleManager::setIgnoreInputStatus(true);
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    Contact *newContact = new Contact{};
    std::string userInput;
    std::cout << '|' << name << '|' << std::endl;
    std::cout << '|' << "Enter new contact name:";
    std::getline(std::cin, userInput);
    newContact->setName(userInput);
    std::cout << std::endl;
    std::cout << '|' << "Enter new contact number:";
    std::getline(std::cin, userInput);
    newContact->setNumber(userInput);
    std::cout << std::endl;
    std::cout << '|' << "Enter new contact birthday(yyyy/mm/dd):";
    std::getline(std::cin, userInput);
    newContact->setDateOfBirth(Date::parseStringToDate(userInput));
    std::cout << std::endl;
    ContactBook::getInstance()->emplace_back(newContact);
    ConsoleManager::returnToPreviousMenu();
    Button *newButton = new Button{
        newContact->getName(),
        ContactMenu::getInstance()->getHeight(),
        ContactMenu::getInstance()->getWidth()};
    newButton->setMenuToRefer(new ContactInfoMenu{newContact->getName(),1,newContact});
    ContactMenu::getInstance()->emplace_back(newButton);
    ConsoleManager::clear();
    ConsoleManager::display(ConsoleManager::getCurrentMenu());
    ConsoleManager::setIgnoreInputStatus(false);
}
