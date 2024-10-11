#pragma once

#include <iostream>
#include <vector>

#include "Visual.h"
#include "Object.h"

class Button;

class Menu : public Visual, Object {
private:
	std::vector<Button> buttons;
	int size;

	Menu() = delete;
public:
	Menu(const std::string& name);

	Menu(const std::string& name, std::vector<Button> buttons);

	void print();
};