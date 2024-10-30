#pragma once

#include "Button.h"

class TimeButton : public Button {
private:
    std::string preciseTime; //точний час доби


public:
    TimeButton() = delete;

    TimeButton(const std::string &name, int height, int width);

    //функція для визначення точного часу доби
    void setPreciseTime(const std::string &newPreciseTime);

    //перевантаження функції виводу в консоль
    void print() override;
};
