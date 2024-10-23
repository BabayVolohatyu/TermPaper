#pragma once

#include "Button.h"

class TimeButton : public Button {
private:
    std::string preciseTime;

    TimeButton() = delete;

public:
    TimeButton(const std::string &name, int height, int width);

    void setPreciseTime(const std::string &preciseTime);

    void print() override;
};
