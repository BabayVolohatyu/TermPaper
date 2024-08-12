#include <string>

#include "../Headers/Account.h"
#include "../Headers/ContactBook.h"

Account* Account::account = nullptr;

ContactBook* Account::contactBook = ContactBook::getInstance();;

Account::Account(const std::string& email)
	:Account{ email, "Username"} {}

Account::Account(const std::string& email, const std::string& name)
	:email{email}, name{name} {
	contactBook =  ContactBook::getInstance();
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
	contactBook->deleteInstance();
	contactBook = nullptr;
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

void Account::getDataFromObject(std::ostream& os) const{
	os << email << std::endl
		<< name << std::endl;
	contactBook->getDataFromObject(os);
}

void Account::setDataToObject(std::istream& is){
	std::string currentLine;
	std::getline(is, currentLine);
	email = currentLine;
	std::getline(is, currentLine);
	name = currentLine;
	contactBook->setDataToObject(is);
}
