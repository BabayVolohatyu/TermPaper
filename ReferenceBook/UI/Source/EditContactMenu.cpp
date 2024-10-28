#include "../Headers/EditContactMenu.h"
#include <windows.h>

#include "../../System/Headers/ContactBook.h"
#include "../Headers/ConsoleManager.h"
#include "../Headers/ContactInfoMenu.h"
#include "../Headers/ContactMenu.h"
#include "../../System/Headers/TimeManager.h"

EditContactMenu::EditContactMenu(Contact *contactToEdit): Menu{"Editing " + contactToEdit->getName()},
                                                          contact{contactToEdit} {
}

EditContactMenu::~EditContactMenu() {
    contact = nullptr;
}

void EditContactMenu::editName() {
    std::cout << "Enter new name: ";
    std::string newName;
    std::getline(std::cin, newName);
    while (newName.empty() || newName == " ") {
        std::cout << "Enter correct new name: ";
        std::getline(std::cin, newName);
    }
    for (int i = 0;i<ContactMenu::getInstance()->getButtons()->size();i++) {
        if (ContactMenu::getInstance()->getButton(i)->getName() == contact->getName()) {
            ContactMenu::getInstance()->getButtons()->erase(ContactMenu::getInstance()->getButtons()->begin() + i);
            contact->setName(newName);
            Button *newButton = new Button{newName,1,ContactMenu::getInstance()->getWidth()};
            ContactInfoMenu* newContactInfoMenu = new ContactInfoMenu{contact->getName(),5,contact};
            newContactInfoMenu->emplace_back(new Button{
            "Edit",
            newContactInfoMenu->getHeight(),
            5
        });
            newContactInfoMenu->getButton(0)->setMenuToRefer(new EditContactMenu{contact});
            newButton->setMenuToRefer(newContactInfoMenu);
            ContactMenu::insert(newButton);
            return;
        }
    }
}

void EditContactMenu::editNumber() {
    std::cout << "Enter new number: ";
    std::string newNumber;
    std::getline(std::cin, newNumber);
    while (newNumber.empty() || newNumber == " ") {
        std::cout << "Enter correct new number: ";
        std::getline(std::cin, newNumber);
    }
    contact->setNumber(newNumber);
}

void EditContactMenu::editDate() {
    std::cout << "Enter new date(yyyy-mm-dd): ";
    std::string newDate;
    std::getline(std::cin, newDate);
    while (newDate.empty() || newDate == " ") {
        std::cout << "Please enter not empty date(yyyy-mm-dd): ";
        std::getline(std::cin, newDate);
    }
    contact->setDateOfBirth(Date::parseStringToDate(newDate));
}

void EditContactMenu::addTag() {
    std::cout << "Enter new tag name: ";
    std::string newTagName;
    std::getline(std::cin, newTagName);
    while (newTagName.empty() || newTagName == " ") {
        std::cout << "Enter correct new tag name: ";
        std::getline(std::cin, newTagName);
    }
    std::cout << "Choose tag color: ";
    ConsoleManager::changeTextColor(Color::BLACK);
    std::cout << "(1)Black(1) ";
    ConsoleManager::changeTextColor(Color::BLUE);
    std::cout << "(2)Blue(2) ";
    ConsoleManager::changeTextColor(Color::GREEN);
    std::cout << "(3)Green(3) ";
    ConsoleManager::changeTextColor(Color::CYAN);
    std::cout << "(4)Cyan(4) ";
    ConsoleManager::changeTextColor(Color::RED);
    std::cout << "(5)Red(5) ";
    ConsoleManager::changeTextColor(Color::MAGENTA);
    std::cout << "(6)Magenta(6) ";
    ConsoleManager::changeTextColor(Color::YELLOW);
    std::cout << "(7)Yellow(7) ";
    ConsoleManager::changeTextColor(Color::WHITE);
    std::cout << "(8)White(8) ";
    ConsoleManager::changeTextColor(Color::GRAY);
    std::cout << "(9)Gray(9) ";
    ConsoleManager::changeTextColor(Color::LIGHT_BLUE);
    std::cout << "(10)Light Blue(10) ";
    ConsoleManager::changeTextColor(Color::LIGHT_GREEN);
    std::cout << "(11)Light Green(11) ";
    ConsoleManager::changeTextColor(Color::LIGHT_CYAN);
    std::cout << "(12)Light Cyan(12) ";
    ConsoleManager::changeTextColor(Color::LIGHT_RED);
    std::cout << "(13)Light Red(13) ";
    ConsoleManager::changeTextColor(Color::LIGHT_MAGENTA);
    std::cout << "(14)Light Magenta(14) ";
    ConsoleManager::changeTextColor(Color::LIGHT_YELLOW);
    std::cout << "(15)Light Yellow(15) ";
    ConsoleManager::changeTextColor(Color::BRIGHT_WHITE);
    std::cout << "(16)Bright White(16) ";
    ConsoleManager::changeTextColor(this->getColor());
    int i = 7;
    Color newColor = static_cast<Color>(i);
    std::cin >> i;
    while (i < 1 || i > 16) {
        std::cout << "Choose correct color: ";
        std::cin.clear();
        std::cin >> i;
    }
    switch (i) {
        case 1:
            newColor = Color::BLACK;
            break;
        case 2:
            newColor = Color::BLUE;
            break;
        case 3:
            newColor = Color::GREEN;
            break;
        case 4:
            newColor = Color::CYAN;
            break;
        case 5:
            newColor = Color::RED;
            break;
        case 6:
            newColor = Color::MAGENTA;
            break;
        case 7:
            newColor = Color::YELLOW;
            break;
        case 8:
            newColor = Color::WHITE;
            break;
        case 9:
            newColor = Color::GRAY;
            break;
        case 10:
            newColor = Color::LIGHT_BLUE;
            break;
        case 11:
            newColor = Color::LIGHT_GREEN;
            break;
        case 12:
            newColor = Color::LIGHT_CYAN;
            break;
        case 13:
            newColor = Color::LIGHT_RED;
            break;
        case 14:
            newColor = Color::LIGHT_MAGENTA;
            break;
        case 15:
            newColor = Color::LIGHT_YELLOW;
            break;
        case 16:
            newColor = Color::BRIGHT_WHITE;
            break;
        default:
            break;
    }
    contact->addTag({newTagName, newColor});
}

void EditContactMenu::deleteTag() {
    std::cout << "Enter name of tag you want to delete: ";
    std::string tagName;
    std::getline(std::cin, tagName);
    while (tagName.empty() || tagName == " ") {
        std::cout << "Enter correct tag name: ";
        std::getline(std::cin, tagName);
    }
    contact->removeTag(tagName);
}

void EditContactMenu::print() {
    std::cout << '|' << name << '|' << std::endl;
    ConsoleManager::setIgnoreInputStatus(true);
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "Press 1 to edit name" << std::endl;
    std::cout << "Press 2 to edit number" << std::endl;
    std::cout << "Press 3 to edit date" << std::endl;
    std::cout << "Press 4 to add tag or 5 to delete" << std::endl;
    std::cout << "Press Backspace to exit" << std::endl;
    while (true) {
        if (GetAsyncKeyState(VK_NUMPAD1) || GetAsyncKeyState('1')) {
            FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
            editName();
            ConsoleManager::refreshButtonBuffer();
        } else if (GetAsyncKeyState(VK_NUMPAD2) || GetAsyncKeyState('2')) {
            FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
            editNumber();
            ConsoleManager::refreshButtonBuffer();
        } else if (GetAsyncKeyState(VK_NUMPAD3) || GetAsyncKeyState('3')) {
            FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
            editDate();
            ConsoleManager::refreshButtonBuffer();
        } else if (GetAsyncKeyState(VK_NUMPAD4) || GetAsyncKeyState('4')) {
            FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
            addTag();
            ConsoleManager::refreshButtonBuffer();
        } else if (GetAsyncKeyState(VK_NUMPAD5) || GetAsyncKeyState('5')) {
            FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
            deleteTag();
            ConsoleManager::refreshButtonBuffer();
        } else if (GetAsyncKeyState(VK_BACK)) {
            TimeManager::getClosestBirthday(ContactBook::getContacts());
            ConsoleManager::setIgnoreInputStatus(false);
            ConsoleManager::refreshButtonBuffer();
            ConsoleManager::clear();
            ConsoleManager::returnToPreviousMenu();
            ConsoleManager::hideCursor();
            ConsoleManager::display(ConsoleManager::getCurrentMenu());
            break;
        }
        ConsoleManager::delay(100);
    }
}
