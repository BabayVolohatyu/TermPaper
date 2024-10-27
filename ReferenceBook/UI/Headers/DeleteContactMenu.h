#pragma once
#include "Menu.h"

class DeleteContactMenu : public Menu {
public:
    DeleteContactMenu();

    ~DeleteContactMenu() override = default;

    void print() override;
};
