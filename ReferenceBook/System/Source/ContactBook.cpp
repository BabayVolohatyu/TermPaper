#include <string>

#include "../Headers/ContactBook.h"
#include "../Headers/Contact.h"

ContactBook *ContactBook::contactBook = nullptr;

ContactBook::ContactBook()
    : contacts{} {
}

ContactBook::~ContactBook() = default;

ContactBook *ContactBook::getInstance() {
    if (!contactBook) {
        contactBook = new ContactBook{};
        return contactBook;
    } else return contactBook;
}

void ContactBook::deleteInstance() {
    for (Contact *contact: contacts) {
        delete contact;
    }
    delete contactBook;
    contactBook = nullptr;
}

void ContactBook::emplace_back(Contact *contact) {
    contacts.emplace_back(contact);
}

void ContactBook::erase(int id) {
    std::vector<Contact *>::iterator it = contacts.begin();
    std::advance(it, id);
    try {
        contacts.erase(it);
    } catch (...) {
        return;
    }
}

int ContactBook::getSize() const {
    return static_cast<int>(contacts.size());
}

Tag ContactBook::getTag(int id) const {
    return tags[id];
}

void ContactBook::addTag(const Tag &tag) {
    for (const Tag &i: tags) {
        if (i == tag) return;
    }
    tags.emplace_back(tag);
}

void ContactBook::removeTag(const std::string &tagName) {
    for (int i = 0; i < tags.size(); i++) {
        if (tags[i].getTagName() == tagName) tags.erase(tags.begin() + i);
    }
}

Contact *ContactBook::getContact(int id) {
    if (id < 0 || id >= contacts.size()) {
        throw std::out_of_range("Invalid index");
    }

    std::vector<Contact *>::iterator it = contacts.begin();
    std::advance(it, id);
    return *it;
}

std::vector<Contact *> ContactBook::getContacts() const {
    return contacts;
}


void ContactBook::getDataFromObject(std::ostream &os) const {
    os << contacts.size() << std::endl;
    for (Contact *contact: contacts) {
        contact->getDataFromObject(os);
    }
}

void ContactBook::setDataToObject(std::istream &is) {
    std::string currentLine;
    std::getline(is, currentLine);
    int numberOfContacts = 0;
    try {
        numberOfContacts = std::stoi(currentLine);
    } catch (...) {
        return;
    }
    for (int i = 0; i < numberOfContacts; i++) {
        Contact *newContact = new Contact();
        newContact->setDataToObject(is);
        contactBook->emplace_back(newContact);
    }
}
