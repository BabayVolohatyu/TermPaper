#pragma once

#include<iostream>

class Serializable {
public:
    virtual ~Serializable() = default;

    //оголошення чистих віртуальних функцій запису та зчитування
    virtual void getDataFromObject(std::ostream &os) const = 0;

    virtual void setDataToObject(std::istream &is) = 0;

    //перевизначення операторів вводу та виводу
    friend std::istream &operator>>(std::istream &is, Serializable &object);

    friend std::ostream &operator<<(std::ostream &os, const Serializable &object);
};
