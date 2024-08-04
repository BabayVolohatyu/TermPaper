#pragma once

#include<iostream>

class Serializable {
public:

	virtual void getDataFromFile(std::istream& is) = 0;

	virtual void setDataToFile(std::ostream& os) const = 0;

	friend std::istream& operator>>(std::istream& is, Serializable& object);

	friend std::ostream& operator<<(std::ostream& os, Serializable& object);

	virtual ~Serializable() = default;
};