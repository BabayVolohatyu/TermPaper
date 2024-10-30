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
    return contact;
}

void ContactInfoMenu::setContact(Contact *newContact) {
   contact = newContact;
}

void ContactInfoMenu::print(){
// Змінюємо колір тексту до поточного кольору
ConsoleManager::changeTextColor(currentColor);

// Ініціалізуємо поля для зберігання інформації про контакт
std::string fieldOfName = this->contact->getName(),
            fieldOfNumber = "Number:" + contact->getNumber(),
            fieldOfDateOfBirth = "Date of birth:" + Date::parseDateToString(contact->getDateOfBirth());

// Визначаємо ширину для відображення полів з врахуванням найбільшого рядка
int tempWidth = static_cast<int>(std::max(fieldOfName.size(),
                                          std::max(fieldOfNumber.size(), fieldOfDateOfBirth.size()))) + 2;
tempWidth += (tempWidth % 2 == 1) ? 1 : 0; // Додаємо 1, якщо ширина непарна для симетрії
int offsetForName = (tempWidth - static_cast<int>(fieldOfName.size())) / 2;
int offsetForNumber = (tempWidth - static_cast<int>(fieldOfNumber.size())) / 2;
int offsetForDate = (tempWidth - static_cast<int>(fieldOfDateOfBirth.size())) / 2;

// Виводимо рядок з іменем і відступом для центрування
std::cout << std::endl;
std::cout << '|';
for (int i = 0; i < offsetForName; i++) {
    std::cout << '~';
}
std::cout << fieldOfName;
offsetForName += (fieldOfName.size() % 2 == 1) ? 1 : 0; // Виправляємо, якщо розмір імені непарний
for (int i = 0; i < offsetForName; i++) {
    std::cout << '~';
}
offsetForName -= (fieldOfName.size() % 2 == 1) ? 1 : 0;
std::cout << '|' << std::endl;

// Виводимо рядок з номером і відступом для центрування
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

// Виводимо рядок з датою народження і відступом для центрування
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

// Виводимо ще раз ім'я для додаткового рядка
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

// Визначаємо максимальний розмір тегу для вирівнювання
int maxTagSize = 0;
for (const Tag &tag : contact->getTags()) {
    if (tag.getTagName().size() > maxTagSize) {
        maxTagSize = static_cast<int>(tag.getTagName().size());
    }
}
tempWidth = maxTagSize + 2;

// Виводимо теги з вирівнюванням по центру
for (Tag &tag : contact->getTags()) {
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

// Виводимо всі кнопки
for (Button *button : buttons) {
    button->print();
}

}
