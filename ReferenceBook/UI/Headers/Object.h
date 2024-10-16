#pragma once

#include <iostream>

class Object {
protected:
    std::string name;
    int width;
    int height;

    Object() = delete;

public:
    Object(const std::string &name,
        int height, int width);

    void setWidth(int width);

    void setHeight(int height);

    int getWidth() const;

    int getHeight() const;

};
