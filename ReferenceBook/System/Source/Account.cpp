#include <string>

#include "../Headers/Account.h"
#include "../Headers/ContactBook.h"
//оголошення статичних змінних
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
	//Якщо об'єкт ще не був створений, то повертаємо новий
	if (!instance) {
		instance = new Account(name);
		return instance;
	}
	return instance;
}

void Account::deleteInstance() {
	contactBook->deleteInstance(); // Видалення об'єкта ContactBook
	contactBook = nullptr; // Очищення вказівника на ContactBook
	delete instance;
	instance = nullptr; // Очищення вказівника на екземпляр
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
	try {
		std::string currentLine;
		std::getline(is, currentLine);
		name = currentLine;
	}catch(...) {
		name = "Guest";
	}
	contactBook->setDataToObject(is);
}
