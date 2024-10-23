#pragma once

#include "Menu.h"

class AddContactMenu : public Menu {
public:
    AddContactMenu();

    ~AddContactMenu() = default;

    void print() override;
};
