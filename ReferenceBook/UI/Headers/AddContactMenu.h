#pragma once

#include <windows.h>

#include "Menu.h"

class AddContactMenu : public Menu {
private:

public:
    AddContactMenu();

    ~AddContactMenu() = default;

    void print() const override;
};
