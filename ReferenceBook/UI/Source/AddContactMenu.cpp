#include "../Headers/AddContactMenu.h"

#include "../../System/Headers/ContactBook.h"
#include "../../System/Headers/Contact.h"
#include "../Headers/ConsoleManager.h"
#include "../Headers/ContactInfoMenu.h"
#include "../Headers/ContactMenu.h"

AddContactMenu::AddContactMenu(): Menu{"New contact", 0} {
}

void AddContactMenu::print() const {
    ConsoleManager::setIgnoreInputStatus(true);
    Contact *newContact = new Contact{};
    std::cout << '|' << name << '|' << std::endl;
    std::cin.ignore();
    std::string userEnter;
    std::cout << '|' << "Enter new contact name:";
    std::getline(std::cin, userEnter);
    newContact->setName(userEnter);
    std::cout << std::endl;
    std::cout << '|' << "Enter new contact number:";
    std::getline(std::cin, userEnter);
    newContact->setNumber(userEnter);
    std::cout << std::endl;
    std::cout << '|' << "Enter new contact birthday(yyyy/mm/dd):";
    std::getline(std::cin, userEnter);
    newContact->setDateOfBirth(Date::parseStringToDate(userEnter));
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
