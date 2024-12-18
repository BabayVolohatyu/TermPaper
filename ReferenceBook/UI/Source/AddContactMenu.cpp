#include <windows.h>

#include "../Headers/AddContactMenu.h"
#include "../../System/Headers/ContactBook.h"
#include "../../System/Headers/Contact.h"
#include "../../System/Headers/TimeManager.h"
#include "../Headers/ConsoleManager.h"
#include "../Headers/ContactInfoMenu.h"
#include "../Headers/ContactMenu.h"
#include "../Headers/EditContactMenu.h"

AddContactMenu::AddContactMenu(): Menu{"New contact", 0} {
}

void AddContactMenu::print() {
    // Встановлюємо статус ігнорування функцій основного меню
    ConsoleManager::setIgnoreInputStatus(true);

    // Очищуємо буфер вводу консолі, видаляючи всі наявні там символи
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

    // Створюємо новий контакт
    Contact *newContact = new Contact{};

    std::string userInput; // Змінна для збереження вводу користувача

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

    //Додаємо новий контакт
    ContactBook::insert(newContact);

    // Повідомлюємо про це наш контроллер часу
    TimeManager::getClosestBirthday(ContactBook::getContacts());

    // Створюємо нову кнопку для цього контакту
    Button *newButton = new Button{
        newContact->getName(),
        ContactMenu::getInstance()->getHeight(),
        ContactMenu::getInstance()->getWidth()
    };

    // Створюємо меню з інформацією про контакт
    ContactInfoMenu *newContactInfoMenu = new ContactInfoMenu{newContact->getName(), 5, newContact};
    newButton->setMenuToRefer(newContactInfoMenu);
    newContactInfoMenu->emplace_back(new Button{
        "Edit",
        newContactInfoMenu->getHeight(),
        5
    });
    newContactInfoMenu->getButton(0)->setMenuToRefer(new EditContactMenu{newContact});

    // Додаємо кнопку контакту до меню контактів
    ContactMenu::insert(newButton);

    // Очищаємо консоль
    ConsoleManager::clear();

    // Оновлюємо буфер кнопок на консолі
    ConsoleManager::refreshButtonBuffer();

    ConsoleManager::returnToPreviousMenu();

    ConsoleManager::display(ConsoleManager::getCurrentMenu());

    // Встановлюємо статус ігнорування функцій основного меню
    ConsoleManager::setIgnoreInputStatus(false);
}
