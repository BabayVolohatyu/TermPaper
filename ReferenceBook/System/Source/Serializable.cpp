#include "../Headers/Serializable.h"

std::istream &operator>>(std::istream &is, Serializable &object) {
    //створення віртуальних функцій було призначене для того, щоб неявно перевантажити
    //оператори вводу і виводу, які тут і викликаються
    object.setDataToObject(is);
    return is;
}

std::ostream &operator<<(std::ostream &os, const Serializable &object) {
    //створення віртуальних функцій було призначене для того, щоб неявно перевантажити
    //оператори вводу і виводу, які тут і викликаються
    object.getDataFromObject(os);
    return os;
}
