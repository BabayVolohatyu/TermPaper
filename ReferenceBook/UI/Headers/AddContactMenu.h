#pragma once

#include "Menu.h"

class AddContactMenu : public Menu {
public:
    AddContactMenu();

    ~AddContactMenu() override = default;

    void print() override;
};
