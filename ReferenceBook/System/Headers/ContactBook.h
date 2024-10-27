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

    ContactBook (ContactBook &&other) = delete;

    ~ContactBook() override = default;

    static ContactBook *getInstance();

    void deleteInstance();

    static void emplace_back(Contact *newContact);

    static void erase(int id);

    static int getSize();

    static Tag getTag(int id);

    static Tag getTag(const std::string& tagName);

    static Contact *getContact(int id);

    static std::vector<Contact *> getContacts();

    static std::vector<Contact*> getContactsWithTag(const std::string& tagName);

    static void addTag(const Tag &tag);

    static void removeTag(const std::string &tagName);

    void getDataFromObject(std::ostream &os) const override;

    void setDataToObject(std::istream &is) override;
};
