#pragma once
#include "Menu.h"
#include "../../System/Headers/Serializable.h"

class UserManualMenu : public Menu, public Serializable{
    private:
    std::string manual;//текст довідника
    public:
    UserManualMenu() = delete;

    UserManualMenu(const std::string &name, int width, const std::string& path);
    //перевантаження функції виводу в консоль
    void print() override;
    //перевантаження функцій запису та зчитування
    void getDataFromObject(std::ostream& os) const override;

    void setDataToObject(std::istream& is) override;
};
