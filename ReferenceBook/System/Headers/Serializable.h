#pragma once

#include<iostream>

class Serializable {
public:
	virtual ~Serializable() = default;

	virtual void getDataFromObject(std::ostream& os) const = 0;

	virtual void setDataToObject(std::istream& is) = 0;

	friend std::istream& operator>>(std::istream& is, Serializable& object);

	friend std::ostream& operator<<(std::ostream& os, const Serializable& object);

};