#include "Serializable.h"

std::istream& operator>>(std::istream& is, Serializable& object){
	object.setDataToObject(is);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Serializable& object){
	object.getDataFromObject(os);
	return os;
}
