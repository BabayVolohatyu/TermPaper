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
    Menu(const std::string &name = "New menu", int width = 10);

    ~Menu() override;

    virtual void emplace_back(Button *button);

    void erase(int index);

    Button *getButton(int index) const;

    std::vector<Button *>* getButtons() ;

    static int getSelectedIndex() ;

    int getSize() const;

    static void selectIndex(int index);

    void print() override;
};
