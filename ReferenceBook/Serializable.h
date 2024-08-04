#pragma once

#include<iostream>

class Serializable {
public:

	virtual void getDataFromObject(std::istream& is) = 0;

	virtual void setDataToObject(std::ostream& os) const = 0;

	friend std::istream& operator>>(std::istream& is, Serializable& object);

	friend std::ostream& operator<<(std::ostream& os, const Serializable& object);

	virtual ~Serializable() = default;
};