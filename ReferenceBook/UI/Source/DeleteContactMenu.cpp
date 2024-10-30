#include <windows.h>

#include "../Headers/DeleteContactMenu.h"
#include "../../System/Headers/Contact.h"
#include "../../System/Headers/ContactBook.h"
#include "../Headers/ConsoleManager.h"
#include "../Headers/ContactMenu.h"
#include "../../System/Headers/TimeManager.h"

DeleteContactMenu::DeleteContactMenu(): Menu{"Deleting contact", 0} {}

void DeleteContactMenu::print() {
    // Встановлюємо статус ігнорування функцій основного меню
    ConsoleManager::setIgnoreInputStatus(true);

    // Очищуємо буфер вводу консолі, видаляючи всі наявні там символи
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

    std::string userInput;

    std::cout << '|' << name << '|' << std::endl;

    std::cout << '|' << "Enter the name of contact you want to delete:";
    std::getline(std::cin, userInput);

    // Шукаємо контакт з введеним іменем у книзі контактів
    int sizeOfBook = ContactBook::getSize();
    for (int i = 0; i < sizeOfBook; i++) {
        if (userInput == ContactBook::getContact(i)->getName()) {
            // Видаляємо контакт, якщо знаходимо збіг
            ContactBook::erase(i);
        }
    }

    // Отримуємо кількість кнопок у меню контактів
    int sizeOfContactBookMenu = ContactMenu::getInstance()->getSize();

    for (int i = 0; i < sizeOfContactBookMenu; i++) {
        if (userInput == ContactMenu::getInstance()->getButton(i)->getName()) {
            // Видаляємо кнопку, якщо знаходимо збіг
            ContactMenu::getInstance()->erase(i);
        }
    }

    // Повідомлюємо про це наш контроллер часу
    TimeManager::getClosestBirthday(ContactBook::getContacts());

    // Повертаємося до попереднього меню
    ConsoleManager::returnToPreviousMenu();

    // Очищаємо консоль і виводимо поточне меню
    ConsoleManager::clear();
    ConsoleManager::display(ConsoleManager::getCurrentMenu());

    // Встановлюємо статус ігнорування функцій основного меню
    ConsoleManager::setIgnoreInputStatus(false);
}

