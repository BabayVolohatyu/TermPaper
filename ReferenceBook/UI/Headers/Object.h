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

    virtual ~Object() = default;

    void setWidth(int width);

    void setHeight(int height);

    void setName(const std::string &name);

    int getWidth() const;

    int getHeight() const;

    std::string getName() const;
};
