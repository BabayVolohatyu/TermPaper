#pragma once
#include "ContactMenu.h"

class SortedContactMenu : public ContactMenu {
    std::vector<Button *> sortedButtons; //відсортовані кнопки
    std::string tagName; //назва тегу, за яким сортувати
public:
    SortedContactMenu();

    ~SortedContactMenu() override = default;

    std::string getTagName();

    [[nodiscard]] Button *getButton(int index) const override;

    [[nodiscard]] int getSize() const override;

    void setTagName(const std::string &newTagName);

    //очищення вектору кнопок
    void clear();

    //перевантаження функції виводу в консоль
    void print() override;
};
