#include "Serializable.h"

std::istream& operator>>(std::istream& is, Serializable& object){
	object.getDataFromFile(is);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Serializable& object){
	object.setDataToFile(os);
	return os;
}
