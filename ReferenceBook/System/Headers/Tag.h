#pragma once
#include "Serializable.h"
#include "../../UI/Headers/Visual.h"

class Tag : public Serializable, public Visual {
private:
    std::string tagName; //ім'я тега

public:
    Tag() = delete;

    Tag(const std::string &tagName = "New Tag", Color color = Color::LIGHT_RED);

    ~Tag() override = default;

    //оголошення гетерів та сетерів
    [[nodiscard]] std::string getTagName() const;

    void setTagName(const std::string &tagName);

    //перевантаження методу виведення в консоль
    void print() override;

    //перевизначення операторів порівняння
    bool operator==(const Tag &other) const;

    bool operator!=(const Tag &other) const;

    bool operator<=(const Tag &other) const = delete;

    bool operator>=(const Tag &other) const = delete;

    bool operator<(const Tag &other) const = delete;

    bool operator>(const Tag &other) const = delete;

    //перевантаження функцій запису та зчитування
    void getDataFromObject(std::ostream &os) const override;

    void setDataToObject(std::istream &is) override;
};
