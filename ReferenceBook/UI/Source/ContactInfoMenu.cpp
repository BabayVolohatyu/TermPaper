#include "../Headers/ContactInfoButton.h"
#include "../../System/Headers/Contact.h"
#include "../Headers/ConsoleManager.h"

ContactInfoButton::ContactInfoButton(const std::string &name, int height, int width): Button{name, height, width},
    contact{nullptr} {
}

Contact *ContactInfoButton::getContact() const {
    return this->contact;
}

void ContactInfoButton::setContact(Contact *contact) {
    this->contact = contact;
}

void ContactInfoButton::print() const {
    ConsoleManager::changeTextColor(currentColor);
    std::cout << std::endl;
    std::cout << '|';
    int offsetForName = (width - contact->getName().size()) / 2;
    for (int i = 0; i < offsetForName; i++) {
        std::cout << '~';
    }
    std::cout << contact->getName();
    for (int i = 0; i < offsetForName; i++) {
        std::cout << '~';
    }
    std::cout << '|' << std::endl;


    std::cout << '|';
    for (int i = 0; i < width; i++) {
        std::cout << ' ';
    }
    std::cout << '|' << std::endl;

    int offsetForNumber = (width - contact->getNumber().size()) / 2;
    std::cout << '|';
    for (int i = 0; i < offsetForNumber; i++) {
        std::cout << ' ';
    }
    std::cout <<"Number:"<< contact->getNumber();
    for (int i = 0; i < offsetForNumber; i++) {
        std::cout << ' ';
    }
    std::cout << '|' << std::endl;

    int offsetForDate = (width - Date::parseDateToString(contact->getDateOfBirth()).size())/2;
    std::cout << '|';
    for (int i = 0; i < offsetForDate; i++) {
        std::cout << ' ';
    }
    std::cout << "Date of birth:"<< Date::parseDateToString(contact->getDateOfBirth());
    for (int i = 0; i < offsetForDate; i++) {
        std::cout << ' ';
    }
    std::cout << '|' << std::endl;
    for (int i = 0; i < offsetForName; i++) {
        std::cout << '~';
    }
    std::cout << contact->getName();
    for (int i = 0; i < offsetForName; i++) {
        std::cout << '~';
    }
    std::cout << '|' << std::endl;

}
