#pragma once

#include <iostream>

#include "Visual.h"
#include "Object.h"

class Button : public Visual, public Object {
private:
    Button() = delete;

public:
    Button(const std::string &name, int height, int width);

    void print() const;
};
