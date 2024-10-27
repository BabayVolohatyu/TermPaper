#pragma once
#include "ContactMenu.h"

class SortedContactMenu: public ContactMenu{
    std::vector<std::pair<Button*, bool>> sortedButtons;
    std::string tagName;
    public:
    SortedContactMenu();

    ~SortedContactMenu() override = default;

    std::string getTagName();

    [[nodiscard]] Button* getButton(int index) const override;

    [[nodiscard]] int getSize() const override;

    void setTagName(const std::string& newTagName);

    void clear();

    void print() override;

};
