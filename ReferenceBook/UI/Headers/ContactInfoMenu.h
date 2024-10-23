#pragma once
#include "Menu.h"

class Contact;

class ContactInfoMenu : public Menu {
    Contact *contact;

    ContactInfoMenu() = delete;

public:
    ContactInfoMenu(const std::string &name, int width, Contact *contact);

    ~ContactInfoMenu() override;

    Contact *getContact() const;

    void setContact(Contact *contact);

    void print() override;
};
