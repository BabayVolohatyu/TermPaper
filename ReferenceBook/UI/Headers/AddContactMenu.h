#pragma once

#include <windows.h>

#include "Menu.h"

class AddContactMenu : public Menu {
public:
    AddContactMenu();

    ~AddContactMenu() = default;

    void print() const override;
};
