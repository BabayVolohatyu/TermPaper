#pragma once

#include <iostream>
#include <vector>

#include "Visual.h"
#include "Object.h"
#include "Button.h"

class Menu : public Visual, public Object {
protected:
    std::vector<Button *> buttons; //кнопки меню
    static int selectedIndex; //індекс на даний момент обраної кнопки


public:
    Menu() = delete;

    Menu(const std::string &name = "New menu", int width = 10);

    ~Menu() override;

    //функція для додавання кнопки
    virtual void emplace_back(Button *button);

    //функція для видалення кнопки
    void erase(int index);

    [[nodiscard]] virtual Button *getButton(int index) const;

    virtual std::vector<Button *> *getButtons();

    static int getSelectedIndex();

    [[nodiscard]] virtual int getSize() const;

    static void selectIndex(int index);

    //функція виводу в консоль
    void print() override;
};
