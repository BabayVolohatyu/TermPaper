#pragma once

#include <iostream>
#include <vector>

#include "Serializable.h"
#include "Tag.h"

class Contact;

class ContactBook : public Serializable {
private:
    static std::vector<Contact *> contacts; //вектор контактів
    static std::vector<Tag> tags; //вектор всіх тегів
    static ContactBook *instance; //поточний об'єкт

    //конструктор приватний за принципом singleton
    ContactBook() = default;

public:
    ContactBook(const ContactBook &other) = delete;

    ContactBook(ContactBook &&other) noexcept = delete;

    ~ContactBook() override = default;

    //оголошення гетерів та сетерів
    static ContactBook *getInstance();

    void deleteInstance();

    static void insert(Contact *newContact);

    static void erase(int id);

    static int getSize();

    static Tag getTag(int id);

    static Tag getTag(const std::string &tagName);

    static Contact *getContact(int id);

    static std::vector<Contact *> getContacts();

    static std::vector<Contact *> getContactsWithTag(const std::string &tagName);

    static void addTag(const Tag &tag);

    static void removeTag(const std::string &tagName);

    //перевизначення функцій запису та зчитування
    void getDataFromObject(std::ostream &os) const override;

    void setDataToObject(std::istream &is) override;
};
