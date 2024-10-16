#include "../Headers/Object.h";

Object::Object(const std::string &name, int height, int width)
    : name{name} {
    if (width < name.size() + 2) width = name.size() + 2;
    if (width % 2 == 0 && name.size() % 2 == 1) width++;
    this->width = width;
    if (height < 3) height = 3;
    this->height = height;
}

void Object::setWidth(int width) {
    this->width = width;
}

void Object::setHeight(int height) {
    this->height = height;
}

int Object::getWidth() const {
    return this->width;
}

int Object::getHeight() const {
    return this->height;
}

