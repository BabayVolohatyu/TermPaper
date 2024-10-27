#pragma once

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

    explicit Contact(const std::string &name);

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

    ~Contact() override;

    [[nodiscard]] std::string getName() const;

    [[nodiscard]] std::string getNumber() const;

    [[nodiscard]] Date getDateOfBirth() const;

    [[nodiscard]] std::vector<Tag> getTags() const;

    [[nodiscard]] Tag getTag(int id) const;

    void addTag(const Tag &tag);

    void removeTag(const std::string& tagName);

    [[nodiscard]] ContactBook *getContactBook() const;

    void setName(const std::string &newName);

    void setNumber(const std::string &newNumber);

    void setContactBook(ContactBook *newContactBook);

    void setDateOfBirth(const Date &newDateOfBirth);

    [[nodiscard]] bool isPresentTag(const Tag &tag) const;

    bool operator==(const Contact &other) const;

    bool operator!=(const Contact &other) const;

    bool operator<=(const Contact &other) const = delete;

    bool operator>=(const Contact &other) const = delete;

    bool operator<(const Contact &other) const;

    bool operator>(const Contact &other) const;

    void getDataFromObject(std::ostream &os) const override;

    void setDataToObject(std::istream &is) override;
};
