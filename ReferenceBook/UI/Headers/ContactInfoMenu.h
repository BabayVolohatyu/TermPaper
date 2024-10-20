#pragma once
#include "Button.h"

class Contact;

class ContactInfoButton : public Button {
    Contact *contact;

    ContactInfoButton() = delete;

public:
    ContactInfoButton(const std::string &name, int height, int width);

    Contact *getContact() const;

    void setContact(Contact *contact);

    void print() const override;
};
