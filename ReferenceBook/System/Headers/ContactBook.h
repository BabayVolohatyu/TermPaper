#pragma once

#include <iostream>
#include <list>
#include <vector>

#include "Serializable.h"
#include "Tag.h"

class Contact;

class ContactBook : public Serializable {
private:
    std::vector<Contact *> contacts;
    std::vector<Tag> tags;
    static ContactBook *contactBook;

    ContactBook();

public:
    ContactBook(const ContactBook &other) = delete;

    ~ContactBook();

    static ContactBook *getInstance();

    void deleteInstance();

    void emplace_back(Contact *contact);

    void erase(int id);

    int getSize() const;

    Tag getTag(int id) const;

    Contact *getContact(int id);

    std::vector<Contact *> getContacts() const;

    void addTag(const Tag &tag);

    void removeTag(const std::string &tagName);

    void getDataFromObject(std::ostream &os) const override;

    void setDataToObject(std::istream &is) override;
};
