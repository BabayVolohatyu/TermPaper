#pragma once
#include "Menu.h"

class DeleteContactMenu : public Menu {
public:
    DeleteContactMenu();

    ~DeleteContactMenu() = default;

    void print() override;
};
