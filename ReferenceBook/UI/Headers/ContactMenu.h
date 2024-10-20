#pragma once

#include "Menu.h"

class ContactMenu : public Menu {
private:
    int offsetToShow;
public:
    ContactMenu(const std::string &name, int width);
    void setOffset(int offset);
    int getOffset();
    void print() const override;
};