#pragma once

#include "Button.h"

class TimeButton : public Button {
private:
    std::string preciseTime;


public:
    TimeButton() = delete;
    TimeButton(const std::string &name, int height, int width);

    void setPreciseTime(const std::string &newPreciseTime);

    void print() override;
};
