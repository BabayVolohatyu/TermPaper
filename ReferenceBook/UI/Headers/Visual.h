#pragma once

#include "../Color.h"

class Visual {
protected:
    Color color = WHITE;
public:
    virtual void print() const = 0;

    virtual ~Visual() = default;

    void setColor(Color color);

    Color getColor() const;
};
