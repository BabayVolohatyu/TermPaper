#include <fstream>

#include "Account.h"
#include "ContactBook.h"

Account* Account::account = nullptr;

ContactBook* Account::contactBook = ContactBook::getInstance();;

Account::Account(const std::string& email)
	:Account{ email, "Username"} {}

Account::Account(const std::string& email, const std::string& name)
	:email{ email }, name{name} {
}

Account::~Account() = default;

Account* Account::getInstance(const std::string& email){
	if (!account) {
		account = new Account(email);
		return account;
	}
	else return account;
}

Account* Account::getInstance(const std::string& email, const std::string& name){
	if (!account) {
		account = new Account(email, name);
		return account;
	}
	else return account;
}

void Account::deleteInstance() {
	delete account;
	account = nullptr;
}
std::string Account::getEmail() const{
	return email;
}

std::string Account::getName() const{
	return name;
}

void Account::setEmail(const std::string& newEmail){
	email = newEmail;
}

void Account::setName(const std::string& newName){
	name = newName;
}
