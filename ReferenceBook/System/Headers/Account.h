#pragma once

#include <iostream>

#include "Serializable.h"

class ContactBook;

class Account : public Serializable {
private:
	static std::string name;
	static Account* instance;

	Account();

	Account(const std::string& name);

public:
	static ContactBook* contactBook;

	Account(const Account& other) = delete;

	~Account() override;

	static Account* getInstance();

	static Account* getInstance(const std::string& name);

	static void deleteInstance();

	static std::string getName();

	static void setName(const std::string& newName);

	static void setEmail(const std::string& newEmail);

	void getDataFromObject(std::ostream& os) const override;

	void setDataToObject(std::istream& is) override;
};