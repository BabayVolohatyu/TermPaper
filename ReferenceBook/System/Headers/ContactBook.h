#pragma once

#include <iostream>
#include <vector>

#include "Serializable.h"
#include "Tag.h"

class Contact;

class ContactBook : public Serializable {
private:
    static std::vector<Contact *> contacts;
    static std::vector<Tag> tags;
    static ContactBook *instance;

    ContactBook() = default;

public:
    ContactBook(const ContactBook &other) = delete;

    ~ContactBook() override;

    static ContactBook *getInstance();

    void deleteInstance();

    static void insert(Contact *newContact);

    static void erase(int id);

    static int getSize();

    static Tag getTag(int id);

    static Contact *getContact(int id);

    static std::vector<Contact *> getContacts();

    static void addTag(const Tag &tag);

    static void removeTag(const std::string &tagName);

    void getDataFromObject(std::ostream &os) const override;

    void setDataToObject(std::istream &is) override;
};
