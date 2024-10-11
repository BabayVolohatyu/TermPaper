#pragma once

#include <iostream>

class Object {
protected:
	std::string name;
	int width;
	int height;

	Object() = delete;

public:
	Object(const std::string& name, int height, int width);

	Object(const Object& other);

	Object(Object&& other);
};