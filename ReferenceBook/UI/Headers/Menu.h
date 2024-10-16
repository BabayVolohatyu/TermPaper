#pragma once

#include <iostream>
#include <vector>

#include "Visual.h"
#include "Object.h"
#include "Button.h"

class Menu : public Visual, public Object {
private:
    std::vector<Button*> buttons;
    Menu() = delete;

public:

    Menu(const std::string &name, int width);

    ~Menu();

    void emplace_back(Button* button);

    Button *getButton(int index);

    void print() const;
};
