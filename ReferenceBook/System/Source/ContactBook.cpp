#include <string>

#include "../Headers/ContactBook.h"
#include "../Headers/Contact.h"

ContactBook *ContactBook::instance = nullptr;
std::vector<Contact *> ContactBook::contacts;
std::vector<Tag> ContactBook::tags;

ContactBook::~ContactBook() = default;

ContactBook *ContactBook::getInstance() {
    if (!instance) {
        instance = new ContactBook{};
        return instance;
    } else return instance;
}

void ContactBook::deleteInstance() {
    for (Contact *contact: contacts) {
        delete contact;
    }
    delete instance;
    instance = nullptr;
}

void ContactBook::emplace_back(Contact *newContact) {
    contacts.emplace_back(newContact);
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

int ContactBook::getSize() {
    return static_cast<int>(contacts.size());
}

Tag ContactBook::getTag(int id) {
    return tags[id];
}

Tag ContactBook::getTag(const std::string &tagName) {
    for(Tag &tag: tags) {
        if(tag.getTagName() == tagName) return tag;
    }
    return {""};
}

void ContactBook::addTag(const Tag &tag) {
    for (const Tag &i: tags) {
        if (i.getTagName() == tag.getTagName()) return;
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

std::vector<Contact *> ContactBook::getContacts(){
    return contacts;
}

std::vector<Contact *> ContactBook::getContactsWithTag(const std::string &tagName) {
    std::vector<Contact *> result;
    for (Contact *contact: contacts) {
        if(contact->isPresentTag(tagName)) result.emplace_back(contact);
    }
    return result;
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
        emplace_back(newContact);
    }
}
