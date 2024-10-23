#pragma once

#include <iostream>

#include "Serializable.h"

class ContactBook;

class Account : public Serializable {
private:
	static std::string email;
	static std::string name;
	static Account* instance;

	Account() = delete;

	Account(const std::string& email);

	Account(const std::string& email, const std::string& name); 

public:
	static ContactBook* contactBook;

	Account(const Account& other) = delete;

	~Account() override;

	static Account* getInstance(const std::string& email);

	static Account* getInstance(const std::string& email, const std::string& name);

	static void deleteInstance();

	static std::string getEmail();

	static std::string getName();

	static void setName(const std::string& newName);

	static void setEmail(const std::string& newEmail);

	void getDataFromObject(std::ostream& os) const override;

	void setDataToObject(std::istream& is) override;
};