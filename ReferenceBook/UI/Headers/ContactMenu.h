#pragma once

#include "Menu.h"

class ContactMenu : public Menu {
private:
    static ContactMenu *instance;


    void emplace_back(Button *button) override {
    }

protected:
    explicit ContactMenu(const std::string &name = "Contacts", int width = 20);

    static int offsetToShow; //поле для обмеження кількості контактів, що показуються в поточний момент

public:
    ~ContactMenu() override;

    static ContactMenu *getInstance(const std::string &name = "Contacts", int width = 20);

    static void insert(Button *newButton);

    static void deleteInstance();

    static void setOffset(int offset);

    static int getOffset();

    //перевантаження функції виводу в консоль
    void print() override;
};
