#include <string>

#include "../Headers/ContactBook.h"
#include "../Headers/Contact.h"

ContactBook *ContactBook::instance = nullptr;
std::vector<Contact *> ContactBook::contacts;
std::vector<Tag> ContactBook::tags;

ContactBook *ContactBook::getInstance() {
    if (!instance) {
        instance = new ContactBook{};
        return instance;
    }
    return instance;
}

void ContactBook::deleteInstance() {
    for (Contact *contact: contacts) {
        delete contact;
        contact = nullptr;
    }
    delete instance;
    instance = nullptr;
}

void ContactBook::insert(Contact *newContact) {
    // Перевіряємо, чи є список контактів порожнім.
    if (contacts.empty())
        // Якщо так, додаємо новий контакт до кінця списку.
        contacts.emplace_back(newContact);
    else {
        // Отримуємо ім'я нового контакту.
        std::string newContactName = newContact->getName();
        // Переводимо ім'я нового контакту до нижнього регістру,
        // щоб порівняння імен не залежало від регістру символів.
        std::transform(newContactName.begin(),
                       newContactName.end(),
                       newContactName.begin(),
                       tolower);

        // Змінна для збереження імен контактів, з якими будемо порівнювати.
        std::string contactToCompareName;

        // Ініціалізуємо ітератор для перебору елементів у векторі
        std::vector<Contact *>::iterator it = contacts.begin();

        // Цикл для проходження по всіх контактах у списку
        for (; it < contacts.end(); it++) {
            // Отримуємо ім'я поточного контакту для порівняння.
            contactToCompareName = (*it)->getName();
            // Приводимо ім'я поточного контакту до нижнього регістру.
            std::transform(contactToCompareName.begin(),
                           contactToCompareName.end(),
                           contactToCompareName.begin(),
                           tolower);

            // Порівнюємо ім'я нового контакту з іменем поточного контакту.
            // Якщо ім'я нового контакту менше поточному,
            // вставляємо новий контакт перед поточним і виходимо з функції.
            if (newContactName < contactToCompareName) {
                contacts.insert(it, newContact);
                return;
            }
        }
        // Якщо жоден з контактів не має умовно більшого імені, ніж новий контакт,
        // додаємо новий контакт у кінець списку.
        contacts.emplace_back(newContact);
    }
}


void ContactBook::erase(int id) {
    try {
        std::vector<Contact *>::iterator it = contacts.begin();
        std::advance(it, id);
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
        id = 0;
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
        Contact *newContact = new Contact{};
        newContact->setDataToObject(is);
        insert(newContact);
    }
}
