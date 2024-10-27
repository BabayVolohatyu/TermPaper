#include "../Headers/Object.h"

Object::Object(const std::string &name, int height, int width)
    : name{name} {
    setWidth(width);
    setHeight(height);
}

void Object::setWidth(int newWidth) {
    if (newWidth < name.size() + 2) newWidth = name.size() + 2;
    if((newWidth-name.size())%2 == 1) newWidth++;
    this->width = newWidth;
}

void Object::setHeight(int newHeight) {
    if (newHeight < 3) newHeight = 3;
    this->height = newHeight;
}

void Object::setName(const std::string &newName) {
    name = newName;
}
int Object::getWidth() const {
    return width;
}

int Object::getHeight() const {
    return height;
}

std::string Object::getName() const {
    return name;
}



