#pragma once

#include <iostream>

#include "Visual.h"
#include "Object.h"

class Menu;

class Button : public Visual, public Object {
private:
    Menu *menuItRefersTo;
public:
    Button() = delete;

    Button(const std::string &name, int height, int width);

    ~Button() override;

    void setMenuToRefer(Menu *menuToRefer);

    Menu *getMenuItRefersTo();

    void print() override;
};


