#include "../Headers/Visual.h"

Color Visual::selectedColor = GREEN;
Color Visual::standardColor = MAGENTA;

void Visual::setColor(Color color) {
    this->currentColor = color;
}

Color Visual::getColor() const {
    return this->currentColor;
}
