#pragma once

#include <iostream>

#include "Serializable.h"
//Попередньо оголошуємо клас контактної книги, який
//буде імпортований у виконавчий файл, адже тут
//нам потрібен не весь клас, а лише його наявність
class ContactBook;

class Account : public Serializable {
private:
    static std::string name; // поле, що відповідає за ім'я користувача
    static Account *instance; // поле, що відповідає за поточний екземпляр об'єкта акаунта
    static ContactBook *contactBook; // поле, що відповідає за книгу контактів

    //конструктори мають бути приватними, адже клас Account дотримується
    //принципу singleton
    Account();

    explicit Account(const std::string &name);

public:
    //видалення конструкторів копіювання та переміщення
    //адже клас Account дотримується принципу singleton
    Account(const Account &other) = delete;

    Account(Account &&other) noexcept = delete;

    ~Account() override;

    //оголошення гетерів та сетерів
    static Account *getInstance(const std::string &name);

    static void deleteInstance();

    static std::string getName();

    static void setName(const std::string &newName);

    //перевантаження функцій запису та зчитування
    void getDataFromObject(std::ostream &os) const override;

    void setDataToObject(std::istream &is) override;
};
