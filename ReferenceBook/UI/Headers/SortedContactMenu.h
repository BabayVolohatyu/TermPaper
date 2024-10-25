#pragma once
#include "ContactMenu.h"

class SortedContactMenu: public ContactMenu{
    std::vector<std::pair<Button*, bool>> sortedButtons;
    std::string tagName;
    public:
    SortedContactMenu();

    std::string getTagName();

    Button* getButton(int index) const override;

    int getSize() const override;

    void setTagName(const std::string& tagName);

    void clear();

    void print() override;

};
