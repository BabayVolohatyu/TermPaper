#pragma once
#include "Menu.h"

class DeleteContactMenu : public Menu {
public:
    DeleteContactMenu();

    ~DeleteContactMenu() override = default;

    //перевантаження функції виводу в консоль
    void print() override;
};
