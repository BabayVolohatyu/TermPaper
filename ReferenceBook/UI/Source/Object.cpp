#include "../Headers/Object.h"

Object::Object(const std::string &name, int height, int width)
    : name{name} {
    setWidth(width);
    setHeight(height);
}

void Object::setWidth(int width) {
    if (width < name.size() + 2) width = name.size() + 2;
    if((width-name.size())%2 == 1) width++;
    this->width = width;
}

void Object::setHeight(int height) {
    if (height < 3) height = 3;
    this->height = height;
}

void Object::setName(const std::string &name) {
    this->name = name;
}
int Object::getWidth() const {
    return this->width;
}

int Object::getHeight() const {
    return this->height;
}

std::string Object::getName() const {
    return this->name;
}



