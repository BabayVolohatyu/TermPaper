#pragma once

#include <iostream>

#include "Serializable.h"

class ContactBook;

class Contact : virtual public Serializable {
private:
	ContactBook* contactBook;
	std::string name;
	std::string number;

	Contact() = delete;

	Contact(const std::string& name);

	Contact(const std::string& name, const std::string& number);

public:

	Contact(const Contact& other);

	Contact(Contact&& other) noexcept;

	~Contact();

	[[nodiscard]] static Contact getInstance(const std::string& name);

	[[nodiscard]] static Contact getInstance(const std::string& name, const std::string& number);

	std::string getName() const;

	std::string getNumber() const;

	ContactBook* getContactBookByReference() const;

	ContactBook& getContactBookByValue() const;
	
	void setName(const std::string& newName);

	void setNumber(const std::string& newNumber);

	void setContactBook(ContactBook* newContactBook);

	bool operator==(const Contact& other) const;

	bool operator!=(const Contact& other) const;

	bool operator<=(const Contact& other) const = delete;

	bool operator>=(const Contact& other) const = delete;

	bool operator<(const Contact& other) const = delete;

	bool operator>(const Contact& other) const = delete;

	void getDataFromObject(std::ostream& os) const override;

	void setDataToObject(std::istream& is) override;
};