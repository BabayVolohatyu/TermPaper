#pragma once

#include <iostream>
#include <vector>

#include "Visual.h"
#include "Object.h"
#include "Button.h"

class Menu : public Visual, public Object {
protected:
    std::vector<Button*> buttons;
    static int selectedIndex;

    Menu() = delete;

public:
    Menu(const std::string &name, int width);

    ~Menu() override;

    void emplace_back(Button *button);

    Button *getButton(int index);

    int getSelectedIndex() const;

    int getSize() const;

    void selectIndex(int index);

    void print() const override;
};
