#pragma once

#include <iostream>

#include "Visual.h"
#include "Object.h"

class Button : public Visual, Object {
private:
	Button() = delete;
public:
	Button(const std::string& name);

	Button(const std::string& name, int size);

	Button(const std::string& name, int width, int height);

	void print();
};