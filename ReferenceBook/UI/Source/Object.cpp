#include "../Headers/Object.h";

Object::Object(const std::string& name, int height, int width)
	:name{ name } {
	if (width < name.size() + 2) width = name.size() + 2;
	if (width % 2 == 0&&name.size()%2==1) width++;
	this->width = width;
	if (height < 4) height = 4;
	if (height % 2 == 1) height++;
	this->height = height;
}