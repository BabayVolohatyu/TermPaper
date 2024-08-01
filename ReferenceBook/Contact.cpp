#include "Contact.h"
#include "ContactBook.h"

Contact::Contact(ContactBook* contactBook)
	:Contact{ contactBook, "New contact", "" } {}

Contact::Contact(ContactBook* contactBook, const std::string& name)
	:Contact{ contactBook,name,"" } {}

Contact::Contact(ContactBook* contactBook, const std::string& name, const std::string& number)
	:contactBook{contactBook}, name{ name }, number{ number } {}

Contact::Contact(const Contact& other)
	:contactBook{ std::move(other.contactBook) }, name(other.name), number{ other.number } {}

Contact::Contact(Contact&& other) noexcept
	:contactBook{ std::move(other.contactBook) }, name{ std::move(other.name) }, number{std::move(other.number)} {}

Contact::~Contact() = default;

Contact Contact::getInstance(ContactBook* contactBook){
	return Contact(contactBook);
}

Contact Contact::getInstance(ContactBook* contactBook, const std::string& name) {
	return Contact(contactBook, name);
}
Contact Contact::getInstance(ContactBook* contactBook, const std::string& name, const std::string& number) {
	return Contact(contactBook, name, number);
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

bool Contact::operator==(const Contact& other) const
{
	if (name != other.name) return false;
	if (number != other.number) return false;
	return true;
}

bool Contact::operator!=(const Contact& other) const
{
	if (name != other.name) return true;
	if (number != other.number) return true;
	return false;
}

void Contact::downloadInfo(const std::string& path){
}

void Contact::uploadInfo(const std::string& path) const{
}



