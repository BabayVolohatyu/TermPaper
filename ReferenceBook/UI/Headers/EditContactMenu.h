#pragma once
#include "Menu.h"
#include "../../System/Headers/Contact.h"

class EditContactMenu : public Menu {
private:
    Contact *contact;

    void editName();

    void editNumber();

    void editDate();

    void addTag();

    void deleteTag();
public:
    EditContactMenu(Contact *contactToEdit);

    ~EditContactMenu() override;

    void print() override;
};
