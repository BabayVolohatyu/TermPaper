#pragma once

#include "../../Enums/Color.h"

class Visual {
protected:
    Color currentColor = MAGENTA;

public:
    static Color selectedColor;
    static Color standardColor;

    virtual void print() const = 0;

    virtual ~Visual() = default;

    void setColor(Color color);

    Color getColor() const;
};
