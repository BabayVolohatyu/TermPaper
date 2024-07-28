#pragma once

#include <iostream>

class ContactBook;

class Contact {
private:
	ContactBook* contactBook;
	std::string name;
	std::string number;

	Contact() = delete;

	explicit Contact(ContactBook* contactBook);

	Contact(ContactBook* contactBook, const std::string& name);

	Contact(ContactBook* contactBook, const std::string& name, const std::string& number);

public:

	Contact(const Contact& other);

	Contact(Contact&& other) noexcept;

	~Contact();

	[[nodiscard]] static Contact getInstance(ContactBook* contactBook);

	[[nodiscard]] static Contact getInstance(ContactBook* contactBook, const std::string& name);

	[[nodiscard]] static Contact getInstance(ContactBook* contactBook, const std::string& name, const std::string& number);

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
};