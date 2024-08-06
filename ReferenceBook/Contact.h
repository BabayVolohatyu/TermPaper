#pragma once

#include <iostream>

#include "Serializable.h"

class ContactBook;

class Contact : public Serializable {
private:
	ContactBook* contactBook;
	std::string name;
	std::string number;
	std::string dateOfBirth;

public:

	Contact();

	Contact(const std::string& name);

	Contact(const std::string& name, const std::string& number);

	Contact(const std::string& name, const std::string& number, const std::string& dateOfBirth);

	Contact(const Contact& other);

	Contact(Contact&& other) noexcept;

	~Contact();

	std::string getName() const;

	std::string getNumber() const;

	std::string getDateOfBirth() const;

	ContactBook* getContactBookByReference() const;

	ContactBook& getContactBookByValue() const;
	
	void setName(const std::string& newName);

	void setNumber(const std::string& newNumber);

	void setContactBook(ContactBook* newContactBook);

	void getDateOfBirth(const std::string& newDateOfBirth);

	bool operator==(const Contact& other) const;

	bool operator!=(const Contact& other) const;

	bool operator<=(const Contact& other) const = delete;

	bool operator>=(const Contact& other) const = delete;

	bool operator<(const Contact& other) const = delete;

	bool operator>(const Contact& other) const = delete;

	void getDataFromObject(std::ostream& os) const override;

	void setDataToObject(std::istream& is) override;
};