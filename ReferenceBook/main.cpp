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
#include "UI/Headers/AddContactMenu.h"
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
    Account *sampleAccount = Account::getInstance("sample@example.com", "Nazar");
    KeySettings keySettings;
    FileManager::downloadFromFile("properties.txt", keySettings);

    Menu *mainMenu = new Menu{"Main menu", 20};
    ConsoleManager::setColorToObject(mainMenu, Color::RED);

    Button *nameButton = new Button{"Welcome, " + sampleAccount->getName() + '!', 1, 50};

    mainMenu->emplace_back(new Button{"Contacts", 1, 1});
    mainMenu->emplace_back(new Button{"Open User Manual(F1)", 1, 4});
    UserManualMenu* userManual = new UserManualMenu("User Manual", 1, "UserManual.txt");
    mainMenu->getButton(1)->setMenuToRefer(userManual);
    TimeButton *timeButton = new TimeButton{Date::parseTimePointToString(Date::getLocalTime()), 5, 5};
    TimeManager::startClockUpdateThread(timeButton);
    ConsoleManager::setColorToObject(timeButton, Color::CYAN);

    ContactMenu *contactsMenu = ContactMenu::getInstance("Contacts menu", 20);
    contactsMenu->emplace_back(new Button{"Add Contact", 1, 1});
    contactsMenu->getButton(0)->setMenuToRefer(new AddContactMenu{});
    contactsMenu->getButton(0)->setColor(Color::RED);
    ContactMenu::setOffset(3);
    mainMenu->getButton(0)->setMenuToRefer(contactsMenu);

    ConsoleManager::setColorToObject(contactsMenu, Color::LIGHT_BLUE);
    for (int i = 0; i < ContactBook::getInstance()->getSize(); i++) {
        contactsMenu->emplace_back(new Button{
            ContactBook::getInstance()->getContact(i)->getName(),
            1, 1
        });
    }
    for (int i = 0; i < ContactBook::getInstance()->getSize(); i++) {
        Contact *contactToRefer = ContactBook::getInstance()->getContact(i);
        contactsMenu->getButton(i)->setMenuToRefer(new ContactInfoMenu("", 1, contactToRefer));
    }
    ConsoleManager::setCurrentMenu(mainMenu);
    ConsoleManager::refreshButtonBuffer();
    ConsoleManager::setIgnoreInputStatus(false);
    while (true) {
        if (GetAsyncKeyState(keySettings.getNextButton())&&!ConsoleManager::getIgnoreInputStatus()) {
            ConsoleManager::refreshButtonBuffer();
            ConsoleManager::selectNextButton(ConsoleManager::getCurrentMenu());
            if (ConsoleManager::getCurrentMenu() == mainMenu) {
                displayMainMenu(mainMenu, nameButton, timeButton);
            } else {
                ConsoleManager::hideCursor();
                ConsoleManager::clear();
                ConsoleManager::display(ConsoleManager::getCurrentMenu());
            }
        } else if (GetAsyncKeyState(keySettings.getPreviousButton())&&!ConsoleManager::getIgnoreInputStatus()) {
            ConsoleManager::refreshButtonBuffer();
            ConsoleManager::selectPreviousButton(ConsoleManager::getCurrentMenu());
            if (ConsoleManager::getCurrentMenu() == mainMenu)displayMainMenu(mainMenu, nameButton, timeButton);
            else {
                ConsoleManager::hideCursor();
                ConsoleManager::clear();
                ConsoleManager::display(ConsoleManager::getCurrentMenu());
            }
        } else if (GetAsyncKeyState(keySettings.getConfirmButton())&&!ConsoleManager::getIgnoreInputStatus()) {
            if (ConsoleManager::getCurrentMenu()->getSelectedIndex() != -1) {
                ConsoleManager::refreshButtonBuffer();
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
        } else if (GetAsyncKeyState(keySettings.getBackButton())&&!ConsoleManager::getIgnoreInputStatus()) {
            ConsoleManager::returnToPreviousMenu();
            if (ConsoleManager::getCurrentMenu() == mainMenu)displayMainMenu(mainMenu, nameButton, timeButton);
            else {
                ConsoleManager::hideCursor();
                ConsoleManager::clear();
                ConsoleManager::display(ConsoleManager::getCurrentMenu());
            }
        } else if (GetAsyncKeyState(keySettings.getQuitButton())&&!ConsoleManager::getIgnoreInputStatus()) {
            ConsoleManager::clear();
            ConsoleManager::changeTextColor(Color::WHITE);
            if(mainMenu)delete mainMenu;
            if(nameButton)delete nameButton;
            if(timeButton)delete timeButton;
            if(contactsMenu!=nullptr)ContactMenu::deleteInstance();
            Account::deleteInstance();
            return 0;
        } else {
            ConsoleManager::delay(1000);
            if (ConsoleManager::getCurrentMenu() == mainMenu) displayMainMenu(mainMenu, nameButton, timeButton);
        }
    }
    return 0;
}
