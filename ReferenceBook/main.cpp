#include <iostream>
#include <chrono>
#include <windows.h>

#include "System/Headers/Account.h"
#include "System/Headers/Contact.h"
#include "System/Headers/ContactBook.h"
#include "System/Headers/FileManager.h"
#include "System/Headers/TimeManager.h"
#include "System/Headers/Date.h"

#include "UI/Headers/Button.h"
#include "UI/Headers/Menu.h"
#include "UI/Headers/ContactMenu.h"
#include "UI/Headers/ContactInfoMenu.h"
#include "UI/Headers/UserManualMenu.h"
#include "UI/Headers/ConsoleManager.h"
#include "UI/Headers/AddContactMenu.h"
#include "Enums/Color.h"
#include "UI/Headers/DeleteContactMenu.h"
#include "UI/Headers/EditContactMenu.h"
#include "UI/Headers/SortedContactMenu.h"


void displayMainMenu(Menu *mainMenu,
                     Button *nameButton,
                     Button *timeButton) {
    if (ConsoleManager::getCurrentMenu() == mainMenu) {
        ConsoleManager::clear();
        ConsoleManager::hideCursor();
        ConsoleManager::display(nameButton);
        ConsoleManager::display(ConsoleManager::getCurrentMenu());
        ConsoleManager::display(timeButton);
    }
}

int main() {
    Account *sampleAccount = Account::getInstance("SampleAccount");
    FileManager::downloadFromFile("../../SampleProject/Accounts/User.txt", *sampleAccount);

    Menu *mainMenu = new Menu{"Main menu", 20};
    ConsoleManager::setColorToObject(mainMenu, Color::RED);

    Button *nameButton = new Button{"Welcome, " + Account::getName() + '!', 1, 50};

    mainMenu->emplace_back(new Button{"Contacts", 1, 1});
    mainMenu->emplace_back(new Button{"Open User Manual(F1)", 1, 4});
    UserManualMenu *userManual = new UserManualMenu("User Manual", 1, "UserManual.txt");
    mainMenu->getButton(1)->setMenuToRefer(userManual);
    TimeButton *timeButton = new TimeButton{Date::parseTimePointToString(Date::getLocalTime()), 5, 5};
    TimeManager::startClockUpdateThread(timeButton);
    ConsoleManager::setColorToObject(timeButton, Color::CYAN);

    ContactMenu *contactsMenu = ContactMenu::getInstance("Contacts menu", 20);
    AddContactMenu *addContactMenu = new AddContactMenu{};
    DeleteContactMenu *deleteContactMenu = new DeleteContactMenu{};
    ContactMenu::setOffset(3);
    mainMenu->getButton(0)->setMenuToRefer(contactsMenu);

    ConsoleManager::setColorToObject(contactsMenu, Color::LIGHT_BLUE);
    for (Contact *contact : ContactBook::getContacts()) {
        Button *contactButton = new Button{contact->getName(), 1, contactsMenu->getWidth()};
        Contact *contactToRefer = contact;
        ContactInfoMenu *newContactInfoMenu = new ContactInfoMenu{"", 10, contactToRefer};
        contactButton->setMenuToRefer(newContactInfoMenu);
        newContactInfoMenu->emplace_back(new Button{
            "Edit",
            newContactInfoMenu->getHeight(),
            6
        });
        newContactInfoMenu->getButton(0)->setMenuToRefer(new EditContactMenu{contactToRefer});
        ContactMenu::insert(contactButton);
    }
    SortedContactMenu *sortedContactMenu = new SortedContactMenu{};
    ConsoleManager::setCurrentMenu(mainMenu);
    ConsoleManager::pushMenu(mainMenu);
    ConsoleManager::refreshButtonBuffer();
    ConsoleManager::setIgnoreInputStatus(false);
    TimeManager::getClosestBirthday(ContactBook::getContacts());
    ConsoleManager::changeCursorVisibilityState();
    ConsoleManager::clear();
    while (true) {
        if (!ConsoleManager::getIgnoreInputStatus()) {
            if (GetAsyncKeyState(VK_TAB) || GetAsyncKeyState(VK_DOWN)) {
                ConsoleManager::selectNextButton(ConsoleManager::getCurrentMenu());
                if (ConsoleManager::getCurrentMenu() == mainMenu) {
                    displayMainMenu(mainMenu, nameButton, timeButton);
                } else {
                    ConsoleManager::hideCursor();
                    ConsoleManager::clear();
                    ConsoleManager::display(ConsoleManager::getCurrentMenu());
                }
            } else if (GetAsyncKeyState(VK_UP) ) {
                ConsoleManager::refreshButtonBuffer();
                ConsoleManager::selectPreviousButton(ConsoleManager::getCurrentMenu());
                if (ConsoleManager::getCurrentMenu() == mainMenu)displayMainMenu(mainMenu, nameButton, timeButton);
                else {
                    ConsoleManager::hideCursor();
                    ConsoleManager::clear();
                    ConsoleManager::display(ConsoleManager::getCurrentMenu());
                }
            } else if (GetAsyncKeyState(VK_RETURN)) {
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
            } else if (GetAsyncKeyState(VK_BACK)) {
                ConsoleManager::returnToPreviousMenu();
                if (ConsoleManager::getCurrentMenu() == mainMenu)displayMainMenu(mainMenu, nameButton, timeButton);
                else {
                    ConsoleManager::hideCursor();
                    ConsoleManager::clear();
                    ConsoleManager::display(ConsoleManager::getCurrentMenu());
                }
                if(ConsoleManager::getCurrentMenu() != sortedContactMenu) {
                    sortedContactMenu->setTagName("");
                    sortedContactMenu->clear();
                }
            }else if(GetAsyncKeyState('d')||GetAsyncKeyState('D')) {
                ConsoleManager::clear();
                ConsoleManager::hideCursor();
                ConsoleManager::pushMenu(ConsoleManager::getCurrentMenu());
                ConsoleManager::setCurrentMenu(deleteContactMenu);
                ConsoleManager::display(ConsoleManager::getCurrentMenu());
            }else if(GetAsyncKeyState('c')||GetAsyncKeyState('C')) {
                ConsoleManager::clear();
                ConsoleManager::hideCursor();
                ConsoleManager::pushMenu(ConsoleManager::getCurrentMenu());
                ConsoleManager::setCurrentMenu(addContactMenu);
                ConsoleManager::display(ConsoleManager::getCurrentMenu());
            } else if(GetAsyncKeyState('s')||GetAsyncKeyState('S')) {
                ConsoleManager::clear();
                ConsoleManager::hideCursor();
                ConsoleManager::pushMenu(ConsoleManager::getCurrentMenu());
                ConsoleManager::setCurrentMenu(sortedContactMenu);
                ConsoleManager::display(ConsoleManager::getCurrentMenu());
            }else if(GetAsyncKeyState(VK_F1)) {
                ConsoleManager::clear();
                ConsoleManager::hideCursor();
                ConsoleManager::pushMenu(ConsoleManager::getCurrentMenu());
                ConsoleManager::setCurrentMenu(userManual);
                ConsoleManager::display(ConsoleManager::getCurrentMenu());
            }else if (GetAsyncKeyState(VK_ESCAPE)) {
                ConsoleManager::changeCursorVisibilityState();
                ConsoleManager::clear();
                ConsoleManager::changeTextColor(Color::WHITE);
                FileManager::uploadToFile("../../SampleProject/Accounts/User.txt", *sampleAccount);
                delete mainMenu;
                delete nameButton;
                delete timeButton;
                delete deleteContactMenu;
                delete addContactMenu;
                delete sortedContactMenu;
                ContactMenu::deleteInstance();
                Account::deleteInstance();
                return 0;
            } else {
                ConsoleManager::delay(1000);
                if (ConsoleManager::getCurrentMenu() == mainMenu) displayMainMenu(mainMenu, nameButton, timeButton);
            }
        }
    }
    return 0;
}
