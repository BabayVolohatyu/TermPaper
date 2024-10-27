#pragma once
#include "Menu.h"

class Contact;

class ContactInfoMenu : public Menu {
    Contact *contact;
public:
    ContactInfoMenu() = delete;
    ContactInfoMenu(const std::string &name, int width, Contact *contact);

    ~ContactInfoMenu() override;

    [[nodiscard]] Contact *getContact() const;

    void setContact(Contact *newContact);

    void print() override;
};
