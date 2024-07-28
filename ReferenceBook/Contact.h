#pragma once

#include <iostream>
#include <memory>

class ContactBook;

class Contact {
private:
	std::shared_ptr<ContactBook> contactBook;
	std::string name;
	std::string number;

	Contact() = delete;

	explicit Contact(std::shared_ptr<ContactBook> contactBook);

	Contact(std::shared_ptr<ContactBook> contactBook, const std::string& name);

	Contact(std::shared_ptr<ContactBook> contactBook, const std::string& name, const std::string& number);

public:

	Contact(const Contact& other);

	Contact(Contact&& other) noexcept;

	~Contact();

	static Contact getInstance(std::shared_ptr<ContactBook> contactBook);

	static Contact getInstance(std::shared_ptr<ContactBook> contactBook, const std::string& name);

	static Contact getInstance(std::shared_ptr<ContactBook> contactBook, const std::string& name, const std::string& number);

	std::string getName() const;

	std::string getNumber() const;

	std::shared_ptr<ContactBook> getContactBookByReference();

	ContactBook getContactBookByValue();
	
	void setName(const std::string& newName);

	void setNumber(const std::string& newNumber);

	void setContactBook(std::shared_ptr<ContactBook> newContactBook);

};