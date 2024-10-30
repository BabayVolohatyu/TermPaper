#pragma once
#include "Menu.h"
#include "../../System/Headers/Contact.h"

class EditContactMenu : public Menu {
private:
    Contact *contact; //контакт, якого потрібно редагувати
    //функції для редагування
    void editName();

    void editNumber();

    void editDate();

    void addTag();

    void deleteTag();

public:
    explicit EditContactMenu(Contact *contactToEdit);

    ~EditContactMenu() override;

    //перевантаження функції виводу в консоль
    void print() override;
};
