#pragma once

#include "Menu.h"

class ContactMenu : public Menu {
private:
    static ContactMenu *instance;
    static int offsetToShow;

    ContactMenu(const std::string &name, int width);

public:

    ~ContactMenu() override;
    static ContactMenu *getInstance(const std::string &name = "Contacts", int width = 20);

    static void deleteInstance();

    static void setOffset(int offset);

    static int getOffset();

    void print() override;
};
