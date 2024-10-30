#pragma once
#include "Menu.h"

class Contact;

class ContactInfoMenu : public Menu {
    Contact *contact; //контакт, інформацію про якого потрібно вивести

public:
    ContactInfoMenu() = delete;

    ContactInfoMenu(const std::string &name, int width, Contact *contact);

    ~ContactInfoMenu() override;

    [[nodiscard]] Contact *getContact() const;

    void setContact(Contact *newContact);

    //перевантаження функції виводу в консоль
    void print() override;
};
