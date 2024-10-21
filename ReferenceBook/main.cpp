#include <iostream>
#include <chrono>
#include <windows.h>

#include "System/Headers/Account.h"
#include "System/Headers/Contact.h"
#include "System/Headers/ContactBook.h"
#include "System/Headers/FileManager.h"
#include "System/Headers/TimeManager.h"
#include "System/Headers/Date.h"
#include "System/Headers/KeySettings.h"

#include "UI/Headers/Button.h"
#include "UI/Headers/Menu.h"
#include "UI/Headers/ContactMenu.h"
#include "UI/Headers/ContactInfoMenu.h"
#include "UI/Headers/UserManualMenu.h"
#include "UI/Headers/ConsoleManager.h"
#include "Enums/Color.h"


void displayMainMenu(const Menu *mainMenu,
                     const Button *nameButton,
                     const Button *timeButton) {
    if (ConsoleManager::getCurrentMenu() == mainMenu) {
        ConsoleManager::clear();
        ConsoleManager::hideCursor();
        ConsoleManager::display(nameButton);
        ConsoleManager::display(ConsoleManager::getCurrentMenu());
        ConsoleManager::display(timeButton);
    }
}

int main() {
    KeySettings keySettings;
    FileManager::downloadFromFile("properties", keySettings);
    Account *account = Account::getInstance("", "Nazar");
    FileManager::downloadFromFile("Accounts/" + account->getName() + ".txt", *account);

    Menu *mainMenu = new Menu{"Main menu", 20};
    ConsoleManager::setColorToObject(mainMenu, Color::RED);

    Button *nameButton = new Button{"Welcome, " + account->getName() + '!', 1, 50};

    mainMenu->emplace_back(new Button{"Contacts", 1, 1});
    mainMenu->emplace_back(new Button{"Settings", 1, 2});
    mainMenu->emplace_back(new Button{"Open User Manual(F1)", 1, 4});

    mainMenu->getButton(1)->setMenuToRefer(mainMenu);
    UserManualMenu* userManual = new UserManualMenu("User Manual", 1, "UserManual.txt");
    mainMenu->getButton(2)->setMenuToRefer(userManual);
    TimeButton *timeButton = new TimeButton{Date::parseTimePointToString(Date::getLocalTime()), 5, 5};
    TimeManager::startClockUpdateThread(timeButton);
    ConsoleManager::setColorToObject(timeButton, Color::CYAN);

    ContactMenu *contactsMenu = new ContactMenu{"Contacts menu", 20};
    contactsMenu->setOffset(3);
    mainMenu->getButton(0)->setMenuToRefer(contactsMenu);

    ConsoleManager::setColorToObject(contactsMenu, Color::LIGHT_BLUE);
    for (int i = 0; i < ContactBook::getInstance()->getSize(); i++) {
        contactsMenu->emplace_back(new Button{
            ContactBook::getInstance()->getContactById(i)->getName(),
            1, 1
        });
    }
    for (int i = 0; i < ContactBook::getInstance()->getSize(); i++) {
        Contact *contactToRefer = ContactBook::getInstance()->getContactById(i);
        contactsMenu->getButton(i)->setMenuToRefer(new ContactInfoMenu("", 1, contactToRefer));
        ConsoleManager::setColorToObject(contactsMenu->getButton(i)->getMenuItRefersTo(), Color::YELLOW);
    }

    Button quitButton{"Quit", 1, 50};
    ConsoleManager::setCurrentMenu(mainMenu);
    while (true) {
        if (GetAsyncKeyState(keySettings.getNextButton())) {
            ConsoleManager::selectNextButton(ConsoleManager::getCurrentMenu());
            if (ConsoleManager::getCurrentMenu() == mainMenu) {
                displayMainMenu(mainMenu, nameButton, timeButton);
            } else {
                ConsoleManager::hideCursor();
                ConsoleManager::clear();
                ConsoleManager::display(ConsoleManager::getCurrentMenu());
            }
        } else if (GetAsyncKeyState(keySettings.getPreviousButton())) {
            ConsoleManager::selectPreviousButton(ConsoleManager::getCurrentMenu());
            if (ConsoleManager::getCurrentMenu() == mainMenu)displayMainMenu(mainMenu, nameButton, timeButton);
            else {
                ConsoleManager::hideCursor();
                ConsoleManager::clear();
                ConsoleManager::display(ConsoleManager::getCurrentMenu());
            }
        } else if (GetAsyncKeyState(keySettings.getConfirmButton())) {
            if (ConsoleManager::getCurrentMenu()->getSelectedIndex() != -1) {
                ConsoleManager::pushMenu(ConsoleManager::getCurrentMenu());
                ConsoleManager::getCurrentMenu()->
                        getButton(ConsoleManager::getCurrentMenu()->
                            getSelectedIndex())->setColor(Visual::standardColor);
                Menu *newMenu = ConsoleManager::getCurrentMenu()->getButton(
                    ConsoleManager::getCurrentMenu()->getSelectedIndex())->getMenuItRefersTo();
                ConsoleManager::setCurrentMenu(newMenu);
                ConsoleManager::getCurrentMenu()->selectIndex(-1);
                if (ConsoleManager::getCurrentMenu() == mainMenu)displayMainMenu(mainMenu, nameButton, timeButton);
                else {
                    ConsoleManager::hideCursor();
                    ConsoleManager::clear();
                    ConsoleManager::display(ConsoleManager::getCurrentMenu());
                }
            }
        } else if (GetAsyncKeyState(keySettings.getBackButton())) {
            ConsoleManager::returnToPreviousMenu();
            if (ConsoleManager::getCurrentMenu() == mainMenu)displayMainMenu(mainMenu, nameButton, timeButton);
            else {
                ConsoleManager::hideCursor();
                ConsoleManager::clear();
                ConsoleManager::display(ConsoleManager::getCurrentMenu());
            }
        } else if (GetAsyncKeyState(keySettings.getQuitButton())) {
            ConsoleManager::clear();
            ConsoleManager::changeTextColor(Color::WHITE);
            delete mainMenu;
            delete nameButton;
            delete timeButton;
            delete contactsMenu;
            delete userManual;
            FileManager::uploadToFile("Accounts/" + account->getName() + ".txt", *account);
            Account::deleteInstance();
            return 0;
        } else {
            ConsoleManager::delay(1000);
        }
    }
    // ConsoleManager::hideCursor();
    // ConsoleManager::display(menu1);
    // ConsoleManager::display(clockButton);
    return 0;
}

// Account *sampleAccount = Account::getInstance("sample@example.com", "Nazar");
// Account::contactBook->emplace_back(Contact{
//     "John",
//     "+380687895245",
//     "2005/12/06"
// });
// Account::contactBook->emplace_back(Contact{
//     "Mark",
//     "+388978567789",
//     "2015/10/09"
// });
//
// Account::contactBook->emplace_back(Contact{
//         "Anna",
//         "+380501234567",
//         "1999/03/15"
//     });
//
// Account::contactBook->emplace_back(Contact{
//         "Oleg",
//         "+380671112233",
//         "1987/07/22"
//     });
//
// Account::contactBook->emplace_back(Contact{
//         "Marta",
//         "+380662223344",
//         "2000/01/30"
//     });
//
// Account::contactBook->emplace_back(Contact{
//         "Ivan",
//         "+380931234567",
//         "1992/11/10"
//     });
//
// Account::contactBook->emplace_back(Contact{
//         "Olena",
//         "+380503334455",
//         "2003/05/25"
//     });
//
// Account::contactBook->emplace_back(Contact{
//         "Taras",
//         "+380632345678",
//         "1995/02/18"
//     });
//
// Account::contactBook->emplace_back(Contact{
//         "Svitlana",
//         "+380673456789",
//         "1984/09/09"
//     });
//
// Account::contactBook->emplace_back(Contact{
//         "Mykola",
//         "+380951234567",
//         "1978/12/01"
//     });
//
// Account::contactBook->emplace_back(Contact{
//         "Nadiya",
//         "+380686789012",
//         "1990/04/07"
//     });
// FileManager::uploadToFile("Accounts/"+sampleAccount->getName()+".txt", *sampleAccount);
