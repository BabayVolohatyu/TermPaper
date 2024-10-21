#include "../../System/Headers/FileManager.h"
#include "../Headers/UserManualMenu.h"

UserManualMenu::UserManualMenu(const std::string &name, int width, const std::string &path)
:Menu{name, width}{
    FileManager::downloadFromFile(path, *this);
}
void UserManualMenu::print() const {
    std::cout << "|";
    for(const char &c : manual) {
        if(c == '\n') std::cout << std::endl <<'|';
        else std::cout << c;
    }
}
void UserManualMenu::getDataFromObject(std::ostream &os) const {}

void UserManualMenu::setDataToObject(std::istream &is) {
    std::string line;
    while (!is.eof()) {
        std::getline(is, line);
        this->manual +=line+'\n';
    };
}




