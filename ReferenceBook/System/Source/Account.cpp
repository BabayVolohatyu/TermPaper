#include <string>

#include "../Headers/Account.h"
#include "../Headers/ContactBook.h"

Account* Account::instance = nullptr;
std::string Account::name;
ContactBook* Account::contactBook = nullptr;

Account::Account()
	:Account{ "Username"} {}

Account::Account(const std::string& name){
	Account::name = name;
	contactBook =  ContactBook::getInstance();
}

Account::~Account() = default;

Account* Account::getInstance(const std::string& name){
	if (!instance) {
		instance = new Account(name);
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

std::string Account::getName(){
	return name;
}

void Account::setName(const std::string& newName){
	name = newName;
}

void Account::getDataFromObject(std::ostream& os) const{
	os << name << std::endl;
	contactBook->getDataFromObject(os);
}

void Account::setDataToObject(std::istream& is){
	std::string currentLine;
	std::getline(is, currentLine);
	name = currentLine;
	contactBook->setDataToObject(is);
}
