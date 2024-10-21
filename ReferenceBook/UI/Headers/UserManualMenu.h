#pragma once
#include "Menu.h"
#include "../../System/Headers/Serializable.h"

class UserManualMenu : public Menu, public Serializable{
    private:
    std::string manual;
    UserManualMenu();
    public:

    UserManualMenu(const std::string &name, int width, const std::string& path);

    void print() const override;

    void getDataFromObject(std::ostream& os) const override;

    void setDataToObject(std::istream& is) override;
};
