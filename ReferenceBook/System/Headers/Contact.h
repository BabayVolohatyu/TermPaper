#pragma once

#include <iostream>

#include "Serializable.h"
#include "Date.h"
#include "Tag.h"

class ContactBook;

class Contact : public Serializable {
private:
    ContactBook *contactBook;
    std::string name;
    std::string number;
    Date dateOfBirth;
    std::vector<Tag> tags;

public:
    Contact();

    Contact(const std::string &name);

    Contact(const std::string &name,
            const std::string &number);

    Contact(const std::string &name,
            const std::string &number,
            const std::string &dateOfBirth);

    Contact(const std::string &name,
            const std::string &number,
            const std::string &dateOfBirth,
            const std::vector<Tag> &tags);

    Contact(const Contact &other);

    Contact(Contact &&other) noexcept;

    ~Contact();

    std::string getName() const;

    std::string getNumber() const;

    Date getDateOfBirth() const;

    std::vector<Tag> getTags() const;

    Tag getTag(int id) const;

    void addTag(const Tag &tag);

    void removeTag(const std::string& tagName);

    ContactBook *getContactBook() const;

    void setName(const std::string &newName);

    void setNumber(const std::string &newNumber);

    void setContactBook(ContactBook *newContactBook);

    void setDateOfBirth(const Date &newDateOfBirth);


    bool operator==(const Contact &other) const;

    bool operator!=(const Contact &other) const;

    bool operator<=(const Contact &other) const = delete;

    bool operator>=(const Contact &other) const = delete;

    bool operator<(const Contact &other) const = delete;

    bool operator>(const Contact &other) const = delete;

    void getDataFromObject(std::ostream &os) const override;

    void setDataToObject(std::istream &is) override;
};
