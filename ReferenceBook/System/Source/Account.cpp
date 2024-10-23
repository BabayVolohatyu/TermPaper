#include <string>

#include "../Headers/Account.h"
#include "../Headers/ContactBook.h"

Account* Account::instance = nullptr;
std::string Account::email;
std::string Account::name;
ContactBook* Account::contactBook = nullptr;

Account::Account(const std::string& email)
	:Account{ email, "Username"} {}

Account::Account(const std::string& email, const std::string& name){
	Account::email = email;
	Account::name = name;
	contactBook =  ContactBook::getInstance();
}

Account::~Account() = default;

Account* Account::getInstance(const std::string& email){
	if (!instance) {
		instance = new Account(email);
		return instance;
	}
	else return instance;
}

Account* Account::getInstance(const std::string& email, const std::string& name){
	if (!instance) {
		instance = new Account(email, name);
		return instance;
	}
	else return instance;
}

void Account::deleteInstance() {
	contactBook->deleteInstance();
	contactBook = nullptr;
	delete instance;
	instance = nullptr;
}
std::string Account::getEmail(){
	return email;
}

std::string Account::getName(){
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
