#include "../Headers/Button.h";

Button::Button(const std::string& name)
	:Button{name, 0, 0} {}

Button::Button(const std::string& name, int size)
	:Button{name, size, size} {}

Button::Button(const std::string& name, int width, int height)
	:Object{name, width, height} {}

void Button::print() {
	// виводимо верхній рядок
	std::cout << ' ';
	for (int i = 0; i < width; i++) {
		std::cout << '-';
	}
	std::cout << std::endl;
	// виводимо бокові до половини
	for (int i = 0; i < height / 2; i++) {
		std::cout << '|';
		for (int j = 0; j < width; j++) {
			std::cout << ' ';
		}
		std::cout << '|';
		std::cout << std::endl;
	}
	// виводимо назву кнопки 
	int offset = (width-name.size())/2;
	if (offset == 0) offset++;
	std::cout << '|';
	for (int i = 0; i < offset; i++) {
		std::cout << ' ';
	}
	std::cout << name;
	for (int i = 0; i < offset; i++) {
		std::cout << ' ';
	}
	std::cout << '|';
	std::cout << std::endl;
	//виводимо другу половину бокових
	for (int i = 0; i < height / 2; i++) {
		std::cout << '|';
		for (int j = 0; j < width; j++) {
			std::cout << ' ';
		}
		std::cout << '|';
		std::cout << std::endl;
	}
	//виводимо нижню
	std::cout << ' ';
	for (int i = 0; i < width; i++) {
		std::cout << '-';
	}
	std::cout << std::endl;
}
