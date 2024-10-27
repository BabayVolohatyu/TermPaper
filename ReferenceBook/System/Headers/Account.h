#pragma once

#include <iostream>

#include "Serializable.h"

class ContactBook;

class Account : public Serializable {
private:
	static std::string name;
	static Account* instance;
	static ContactBook* contactBook;
	Account();

	explicit Account(const std::string& name);

public:

	Account(const Account& other) = delete;

	~Account() override;

	static Account* getInstance(const std::string& name);

	static void deleteInstance();

	static std::string getName();

	static void setName(const std::string& newName);

	void getDataFromObject(std::ostream& os) const override;

	void setDataToObject(std::istream& is) override;
};