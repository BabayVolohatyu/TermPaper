#pragma once

#include "Menu.h"

class AddContactMenu : public Menu {
public:
    AddContactMenu();

    ~AddContactMenu() override = default;

    //перевантаження функції виводу в консоль
    void print() override;
};
