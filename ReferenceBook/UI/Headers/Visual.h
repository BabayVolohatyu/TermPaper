#pragma once

#include "../../Enums/Color.h"

class Visual {
protected:
    Color currentColor = Color::MAGENTA;

public:
    static Color selectedColor;
    static Color standardColor;

    virtual void print() = 0;

    virtual ~Visual() = default;

    void setColor(Color color);

    [[nodiscard]] Color getColor() const;
};
