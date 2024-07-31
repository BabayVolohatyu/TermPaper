#pragma once

#include <iostream>

class ContactBook;

class Account {
private:
	std::string email;
	std::string name;
	static ContactBook* contactBook;
	static Account* account;

	Account() = delete;

	Account(const std::string& email);

	Account(const std::string& email, const std::string& name); 

public:

	Account(const Account& other) = delete;

	~Account();

	static Account* getInstance(const std::string& email);

	static Account* getInstance(const std::string& email, const std::string& name);

	std::string getEmail() const;

	std::string getName() const;

	void setName(const std::string& newName);

	void setEmail(const std::string& newEmail);

};