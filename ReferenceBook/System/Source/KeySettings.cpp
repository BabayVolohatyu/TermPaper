#include "../Headers/KeySettings.h"

KeySettings::KeySettings()
    : quitButton{KeyCode::ESC},
      backButton{KeyCode::DOWN_ARROW},
      previousButton{KeyCode::UP_ARROW},
      confirmButton{KeyCode::C},
      cancelButton{KeyCode::X},
      editButton{KeyCode::E} {
}

int KeySettings::getQuitButton() {
    return static_cast<int>(quitButton);
}

int KeySettings::getBackButton() {
    return static_cast<int>(backButton);
}

int KeySettings::getNextButton() {
    return static_cast<int>(nextButton);
}

int KeySettings::getPreviousButton() {
    return static_cast<int>(previousButton);
}

int KeySettings::getConfirmButton() {
    return static_cast<int>(confirmButton);
}

int KeySettings::getCancelButton() {
    return static_cast<int>(cancelButton);
}

int KeySettings::getEditButton() {
    return static_cast<int>(editButton);
}

void KeySettings::setQuitButton(KeyCode key) {
    quitButton = key;
}

void KeySettings::setBackButton(KeyCode key) {
    backButton = key;
}

void KeySettings::setNextButton(KeyCode key) {
    nextButton = key;
}

void KeySettings::setPreviousButton(KeyCode key) {
    previousButton = key;
}

void KeySettings::setConfirmButton(KeyCode key) {
    confirmButton = key;
}

void KeySettings::setCancelButton(KeyCode key) {
    cancelButton = key;
}

void KeySettings::setEditButton(KeyCode key) {
    editButton = key;
}

void KeySettings::getDataFromObject(std::ostream &os) const {
    os << static_cast<int>(quitButton) << std::endl
            << static_cast<int>(backButton) << std::endl
            << static_cast<int>(nextButton) << std::endl
            << static_cast<int>(previousButton) << std::endl
            << static_cast<int>(confirmButton) << std::endl
            << static_cast<int>(cancelButton) << std::endl
            << static_cast<int>(editButton) << std::endl;
}

void KeySettings::setDataToObject(std::istream &is) {
    std::string currentLine;
    std::getline(is, currentLine);
    quitButton = static_cast<KeyCode>(std::stoi(currentLine));
    std::getline(is, currentLine);
    backButton = static_cast<KeyCode>(std::stoi(currentLine));
    std::getline(is, currentLine);
    nextButton = static_cast<KeyCode>(std::stoi(currentLine));
    std::getline(is, currentLine);
    previousButton = static_cast<KeyCode>(std::stoi(currentLine));
    std::getline(is, currentLine);
    confirmButton = static_cast<KeyCode>(std::stoi(currentLine));
    std::getline(is, currentLine);
    cancelButton = static_cast<KeyCode>(std::stoi(currentLine));
    std::getline(is, currentLine);
    editButton = static_cast<KeyCode>(std::stoi(currentLine));
}
