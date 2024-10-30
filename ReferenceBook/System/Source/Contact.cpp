#include <string>

#include "../Headers/Contact.h"
#include "../Headers/ContactBook.h"

Contact::Contact()
    : Contact{
        "Empty",
        "Empty",
        "2000/01/01",
        {}
    } {
}

Contact::Contact(const std::string &name)
    : Contact{
        name,
        "Empty",
        "2000/01/01",
        {}
    } {
}

Contact::Contact(const std::string &name,
                 const std::string &number)
    : Contact{
        name,
        number,
        "2005/01/01",
        {}
    } {
}

Contact::Contact(const std::string &name,
                 const std::string &number,
                 const std::string &dateOfBirth)
    : Contact{name, number, dateOfBirth, {}} {
}

Contact::Contact(const std::string &name,
                 const std::string &number,
                 const std::string &dateOfBirth,
                 const std::vector<Tag> &tags)
    : contactBook{ContactBook::getInstance()},
      name{name},
      number{number},
      dateOfBirth{Date::parseStringToDate(dateOfBirth)},
      tags{tags} {
}

Contact::Contact(const Contact &other)
    : contactBook{other.contactBook},
      name{other.name},
      number{other.number},
      dateOfBirth{other.dateOfBirth},
      tags{other.tags} {
}

Contact::Contact(Contact &&other) noexcept
    : contactBook{other.contactBook},
      name{std::move(other.name)},
      number{std::move(other.number)},
      dateOfBirth{std::move(other.dateOfBirth)},
      tags{std::move(other.tags)} {
}

Contact::~Contact() {
    contactBook = nullptr;
};

std::string Contact::getName() const {
    return name;
}

std::string Contact::getNumber() const {
    return number;
}

Date Contact::getDateOfBirth() const {
    return dateOfBirth;
}

std::vector<Tag> Contact::getTags() const {
    return tags;
}

Tag Contact::getTag(int id) const {
    return tags[id];
}

void Contact::addTag(const Tag &tag) {
    tags.emplace_back(tag);
}

void Contact::removeTag(const std::string &tagName) {
    for (int i = 0; i < tags.size(); i++) {
        if (tags[i].getTagName() == tagName)
            tags.erase(tags.begin() + i);
        i--;
    }
}

ContactBook *Contact::getContactBook() const {
    return contactBook;
}

void Contact::setName(const std::string &newName) {
    name = newName;
}

void Contact::setNumber(const std::string &newNumber) {
    number = newNumber;
}

void Contact::setDateOfBirth(const Date &newDateOfBirth) {
    dateOfBirth = newDateOfBirth;
}

bool Contact::isPresentTag(const Tag &tag) const {
    if (tags.empty()) return false;
    for (const Tag &t: tags) {
        if (t.getTagName() == tag.getTagName()) return true;
    }
    return false;
}

void Contact::setContactBook(ContactBook *newContactBook) {
    contactBook = newContactBook;
}

bool Contact::operator==(const Contact &other) const {
    if (name != other.name) return false;
    if (number != other.number) return false;
    if (dateOfBirth != other.dateOfBirth) return false;
    if (tags != other.tags) return false;
    return true;
}

bool Contact::operator!=(const Contact &other) const {
    if (name != other.name) return true;
    if (number != other.number) return true;
    if (dateOfBirth != other.dateOfBirth) return true;
    if (tags != other.tags) return true;
    return false;
}

bool Contact::operator<(const Contact &other) const {
    std::string lowerName = name;
    std::string lowerNameOther = other.name;
    return std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), tolower) <
           std::transform(lowerNameOther.begin(), lowerNameOther.end(), lowerNameOther.begin(), tolower);
}

bool Contact::operator>(const Contact &other) const {
    std::string lowerName = name;
    std::string lowerNameOther = other.name;
    return std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), tolower) >
           std::transform(lowerNameOther.begin(), lowerNameOther.end(), lowerNameOther.begin(), tolower);
}

void Contact::getDataFromObject(std::ostream &os) const {
    os << name << std::endl
            << number << std::endl
            << Date::parseDateToString(dateOfBirth) << std::endl;
    os << tags.size() << std::endl;
    for (const Tag &tag: tags) {
        tag.getDataFromObject(os);
    }
}

void Contact::setDataToObject(std::istream &is) {
    std::string currentLine;
    try {
        std::getline(is, currentLine);
        name = currentLine;
        std::getline(is, currentLine);
        number = currentLine;
        std::getline(is, currentLine);
        dateOfBirth = Date::parseStringToDate(currentLine);
        std::getline(is, currentLine);
    } catch (...) {
        name = "New Contact";
        number = "";
        dateOfBirth = Date{2000, 1, 1};
    }
    int numberOfTags = std::stoi(currentLine);
    for (int i = 0; i < numberOfTags; i++) {
        Tag newTag = Tag{currentLine};
        newTag.setDataToObject(is);
        tags.emplace_back(newTag);
        ContactBook::addTag(newTag);
    }
}
