#pragma once

#include <iostream>

class Object {
protected:
    std::string name;
    int width;
    int height;
public:
    Object() = delete;
    Object(const std::string &name, int height, int width);

    virtual ~Object() = default;

    void setWidth(int newWidth);

    void setHeight(int newHeight);

    void setName(const std::string &newName);

    [[nodiscard]] int getWidth() const;

    [[nodiscard]] int getHeight() const;

    [[nodiscard]] std::string getName() const;
};
