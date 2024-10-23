#include "../Headers/ContactInfoMenu.h"
#include "../../System/Headers/Contact.h"
#include "../Headers/ConsoleManager.h"

ContactInfoMenu::ContactInfoMenu(const std::string &name, int width, Contact *contact): Menu{name, width},
    contact{contact} {
}

ContactInfoMenu::~ContactInfoMenu() {
    contact = nullptr;
}

Contact *ContactInfoMenu::getContact() const {
    return this->contact;
}

void ContactInfoMenu::setContact(Contact *contact) {
    this->contact = contact;
}

void ContactInfoMenu::print() {
    ConsoleManager::changeTextColor(currentColor);
    std::string fieldOfName = this->contact->getName(),
            fieldOfNumber = "Number:" + contact->getNumber(),
            fieldOfDateOfBirth = "Date of birth:" + Date::parseDateToString(contact->getDateOfBirth());

    int tempWidth = static_cast<int>(std::max(fieldOfName.size(),
                                              std::max(fieldOfNumber.size(), fieldOfDateOfBirth.size()))) + 2;
    tempWidth += (tempWidth % 2 == 1) ? 1 : 0;
    int offsetForName = (tempWidth - static_cast<int>(fieldOfName.size())) / 2;
    int offsetForNumber = (tempWidth - static_cast<int>(fieldOfNumber.size())) / 2;
    int offsetForDate = (tempWidth - static_cast<int>(fieldOfDateOfBirth.size())) / 2;

    std::cout << std::endl;
    std::cout << '|';
    for (int i = 0; i < offsetForName; i++) {
        std::cout << '~';
    }
    std::cout << fieldOfName;
    offsetForName += (fieldOfName.size() % 2 == 1) ? 1 : 0;
    for (int i = 0; i < offsetForName; i++) {
        std::cout << '~';
    }
    offsetForName -= (fieldOfName.size() % 2 == 1) ? 1 : 0;
    std::cout << '|' << std::endl;

    std::cout << '|';
    for (int i = 0; i < offsetForNumber; i++) {
        std::cout << ' ';
    }
    std::cout << fieldOfNumber;
    offsetForNumber += (fieldOfNumber.size() % 2 == 1) ? 1 : 0;
    for (int i = 0; i < offsetForNumber; i++) {
        std::cout << ' ';
    }
    std::cout << '|' << std::endl;

    std::cout << '|';
    for (int i = 0; i < offsetForDate; i++) {
        std::cout << ' ';
    }
    std::cout << fieldOfDateOfBirth;
    offsetForDate += (fieldOfDateOfBirth.size() % 2 == 1) ? 1 : 0;
    for (int i = 0; i < offsetForDate; i++) {
        std::cout << ' ';
    }
    std::cout << '|' << std::endl;

    std::cout << '|';
    for (int i = 0; i < offsetForName; i++) {
        std::cout << '~';
    }
    std::cout << fieldOfName;
    offsetForName += (fieldOfName.size() % 2 == 1) ? 1 : 0;
    for (int i = 0; i < offsetForName; i++) {
        std::cout << '~';
    }
    std::cout << '|' << std::endl;

    int maxTagSize = 0;
    for (const Tag &tag: this->contact->getTags()) {
        if (tag.getTagName().size() > maxTagSize) {
            maxTagSize = static_cast<int>(tag.getTagName().size());
        }
    }
    tempWidth = maxTagSize + 2;

    for (const Tag &tag : this->contact->getTags()) {
        std::cout << '|';

        int offsetForTag = (tempWidth - static_cast<int>(tag.getTagName().size())) / 2;

        for (int i = 0; i < offsetForTag; i++) {
            std::cout << ' ';
        }

        tag.print();


        for (int i = 0; i < (tempWidth - static_cast<int>(tag.getTagName().size()) - offsetForTag); i++) {
            std::cout << ' ';
        }

        std::cout << '|' << std::endl;
    }
}
