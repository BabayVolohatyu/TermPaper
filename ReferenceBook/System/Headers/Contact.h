#pragma once

#include "Serializable.h"
#include "Date.h"
#include "Tag.h"

//Попередньо оголошуємо клас контактної книги, який
//буде імпортований у виконавчий файл, адже тут
//нам потрібен не весь клас, а лише його наявність
class ContactBook;

class Contact : public Serializable {
private:
    ContactBook *contactBook; // Поле, що відповідає за книгу контактів
    std::string name; // Ім'я контакту
    std::string number; // Номер телефону контакту
    Date dateOfBirth; // Дата народження контакту
    std::vector<Tag> tags; // Вектор тегів, пов'язаних з контактом

public:
    //оголошення конструкторів
    Contact();

    explicit Contact(const std::string &name);

    Contact(const std::string &name,
            const std::string &number);

    Contact(const std::string &name,
            const std::string &number,
            const std::string &dateOfBirth);

    Contact(const std::string &name,
            const std::string &number,
            const std::string &dateOfBirth,
            const std::vector<Tag> &tags);

    Contact(const Contact &other);

    Contact(Contact &&other) noexcept;

    ~Contact() override;

    //оголошення гетерів та сетерів
    [[nodiscard]] std::string getName() const;

    [[nodiscard]] std::string getNumber() const;

    [[nodiscard]] Date getDateOfBirth() const;

    [[nodiscard]] std::vector<Tag> getTags() const;

    [[nodiscard]] Tag getTag(int id) const;

    void addTag(const Tag &tag);

    void removeTag(const std::string &tagName);

    [[nodiscard]] ContactBook *getContactBook() const;

    void setName(const std::string &newName);

    void setNumber(const std::string &newNumber);

    void setContactBook(ContactBook *newContactBook);

    void setDateOfBirth(const Date &newDateOfBirth);

    //функція на перевірку наявності тега
    [[nodiscard]] bool isPresentTag(const Tag &tag) const;

    //перевизначення операторів порівняння
    bool operator==(const Contact &other) const;

    bool operator!=(const Contact &other) const;

    bool operator<=(const Contact &other) const = delete;

    bool operator>=(const Contact &other) const = delete;

    bool operator<(const Contact &other) const;

    bool operator>(const Contact &other) const;

    //перевантаження функцій запису та зчитування
    void getDataFromObject(std::ostream &os) const override;

    void setDataToObject(std::istream &is) override;
};
