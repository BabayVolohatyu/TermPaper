#include "../Headers/Tag.h"

#include "../../UI/Headers/ConsoleManager.h"

Tag::Tag(const std::string &tagName, Color color)
    : tagName{tagName} {
    currentColor = color;
}

std::string Tag::getTagName() const {
    return this->tagName;
}

void Tag::setTagName(const std::string &tagName) {
    this->tagName = tagName;
}

void Tag::print() {
    ConsoleManager::changeTextColor(this->getColor());
    std::cout << '[' << tagName << ']';
    ConsoleManager::changeTextColor(ConsoleManager::getCurrentMenu()->getColor());
}

bool Tag::operator==(const Tag &other) const {
    return this->tagName == other.tagName
           && this->currentColor == other.currentColor;
}

bool Tag::operator!=(const Tag &other) const {
    return this->tagName != other.tagName
           || this->currentColor != other.currentColor;
}

void Tag::getDataFromObject(std::ostream &os) const {
    os << this->tagName << std::endl
            << static_cast<int>(this->currentColor) << std::endl;
}

void Tag::setDataToObject(std::istream &is) {
    std::string currentline;
    std::getline(is, currentline);
    this->tagName = currentline;
    std::getline(is, currentline);
    this->currentColor = static_cast<Color>(std::stoi(currentline));
}
