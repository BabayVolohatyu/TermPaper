#include "Contact.h"
#include "ContactBook.h"

Contact::Contact(const std::string& name)
	:Contact{name,"" } {}

Contact::Contact(const std::string& name, const std::string& number)
	:contactBook{ContactBook::getInstance()}, name{name}, number{number} {}

Contact::Contact(const Contact& other)
	:contactBook{ std::move(other.contactBook) }, name(other.name), number{ other.number } {}

Contact::Contact(Contact&& other) noexcept
	:contactBook{ std::move(other.contactBook) }, name{ std::move(other.name) }, number{std::move(other.number)} {}

Contact::~Contact() = default;

Contact Contact::getInstance(const std::string& name) {
	return Contact(name);
}
Contact Contact::getInstance(const std::string& name, const std::string& number) {
	return Contact(name, number);
}

std::string Contact::getName() const{
	return name;
}

std::string Contact::getNumber() const{
	return number;
}

ContactBook* Contact::getContactBookByReference() const{
	return contactBook;
}

ContactBook& Contact::getContactBookByValue() const{
	return *contactBook;
}

void Contact::setName(const std::string& newName){
	name = newName;
}

void Contact::setNumber(const std::string& newNumber){
	number = newNumber;
}

void Contact::setContactBook(ContactBook* newContactBook){
	contactBook = newContactBook;
}

bool Contact::operator==(const Contact& other) const{
	if (name != other.name) return false;
	if (number != other.number) return false;
	return true;
}

bool Contact::operator!=(const Contact& other) const{
	if (name != other.name) return true;
	if (number != other.number) return true;
	return false;
}

void Contact::getDataFromObject(std::ostream& os) const {
	os << name << std::endl
		 << number << std::endl;
}

void Contact::setDataToObject(std::istream& is) {

}