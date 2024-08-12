#include <string>

#include "../Headers/Contact.h"
#include "../Headers/ContactBook.h"

Contact::Contact()
	:Contact{"Noname","2005/01/01",} {}

Contact::Contact(const std::string& name)
	:Contact{name,"","2005/01/01"} {}

Contact::Contact(const std::string& name, const std::string& number)
	:Contact{name,number,"2005/01/01"} {}

Contact::Contact(const std::string& name, const std::string& number, 
	const std::string& dateOfBirth)
	:contactBook{ ContactBook::getInstance() }, name{ name }, number{ number }, 
	dateOfBirth{dateOfBirth} {}

Contact::Contact(const Contact& other)
	:contactBook{ other.contactBook }, name{ other.name }, number{ other.number },
	dateOfBirth{other.dateOfBirth} {}

Contact::Contact(Contact&& other) noexcept
	:contactBook{ std::move(other.contactBook) }, name{ std::move(other.name) }, 
	number{std::move(other.number)}, dateOfBirth{ std::move(other.dateOfBirth) } {}

Contact::~Contact() {
	contactBook = nullptr;
};

std::string Contact::getName() const{
	return name;
}

std::string Contact::getNumber() const{
	return number;
}

std::string Contact::getDateOfBirth() const {
	return dateOfBirth;
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

void Contact::getDateOfBirth(const std::string& newDateOfBirth) {
	dateOfBirth = newDateOfBirth;
}

void Contact::setContactBook(ContactBook* newContactBook){
	contactBook = newContactBook;
}

bool Contact::operator==(const Contact& other) const{
	if (name != other.name) return false;
	if (number != other.number) return false;
	if (dateOfBirth != other.dateOfBirth) return false;
	return true;
}

bool Contact::operator!=(const Contact& other) const{
	if (name != other.name) return true;
	if (number != other.number) return true;
	if (dateOfBirth != other.dateOfBirth) return true;
	return false;
}

void Contact::getDataFromObject(std::ostream& os) const {
	os << name << std::endl
		<< number << std::endl
		<< dateOfBirth << std::endl;

}

void Contact::setDataToObject(std::istream& is) {
	std::string currentLine;
	std::getline(is, currentLine);
	name = currentLine;
	std::getline(is, currentLine);
	number = currentLine;
	std::getline(is, currentLine);
	dateOfBirth = currentLine;
}