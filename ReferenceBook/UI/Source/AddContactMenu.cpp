#include <windows.h>
#include "../Headers/AddContactMenu.h"

#include "../../System/Headers/ContactBook.h"
#include "../../System/Headers/Contact.h"
#include "../Headers/ConsoleManager.h"
#include "../Headers/ContactInfoMenu.h"
#include "../Headers/ContactMenu.h"
#include "../Headers/EditContactMenu.h"

AddContactMenu::AddContactMenu(): Menu{"New contact", 0} {}

void AddContactMenu::print() {
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
    ContactBook::emplace_back(newContact);
    Button *newButton = new Button{
        newContact->getName(),
        ContactMenu::getInstance()->getHeight(),
        ContactMenu::getInstance()->getWidth()};
    ContactInfoMenu *newContactInfoMenu = new ContactInfoMenu{newContact->getName(),5,newContact};
    newButton->setMenuToRefer(newContactInfoMenu);
    newContactInfoMenu->emplace_back(new Button{
            "Edit",
            newContactInfoMenu->getHeight(),
            5
        });
    newContactInfoMenu->getButton(0)->setMenuToRefer(new EditContactMenu{newContact});
    ContactMenu::insert(newButton);
    ConsoleManager::clear();
    ConsoleManager::refreshButtonBuffer();
    ConsoleManager::returnToPreviousMenu();
    ConsoleManager::display(ConsoleManager::getCurrentMenu());
    ConsoleManager::setIgnoreInputStatus(false);
}
