#include "../Headers/Visual.h"

Color Visual::selectedColor = Color::GREEN;
Color Visual::standardColor = Color::MAGENTA;

void Visual::setColor(Color color) {
    currentColor = color;
}

Color Visual::getColor() const {
    return currentColor;
}
