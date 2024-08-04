#include "Serializable.h"

std::istream& operator>>(std::istream& is, Serializable& object){
	object.getDataFromObject(is);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Serializable& object){
	object.setDataToObject(os);
	return os;
}
