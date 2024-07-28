#include "Contact.h"
#include "ContactBook.h"

Contact::Contact(std::shared_ptr<ContactBook> contactBook)
	:Contact{ contactBook, "New contact", "" } {}

Contact::Contact(std::shared_ptr<ContactBook> contactBook, const std::string& name)
	:Contact{ contactBook,name,"" } {}

Contact::Contact(std::shared_ptr<ContactBook> contactBook, const std::string& name, const std::string& number)
	:contactBook{ contactBook }, name{ name }, number{ number } {}

Contact::Contact(const Contact &other)
	:contactBook{ other.contactBook }, name{ other.name }, number{other.number} {}

Contact::Contact(Contact &&other) noexcept
	:contactBook{ std::move(other.contactBook) }, name{ std::move(other.name) }, number{std::move(other.number)} {}

Contact::~Contact() = default;

Contact Contact::getInstance(std::shared_ptr<ContactBook> contactBook){
	return Contact(contactBook);
}

Contact Contact::getInstance(std::shared_ptr<ContactBook> contactBook, const std::string& name) {
	return Contact(contactBook, name);
}
Contact Contact::getInstance(std::shared_ptr<ContactBook> contactBook, const std::string& name, const std::string& number) {
	return Contact(contactBook, name, number);
}

std::string Contact::getName() const
{
	return name;
}

std::string Contact::getNumber() const
{
	return number;
}

std::shared_ptr<ContactBook> Contact::getContactBookByReference()
{
	return contactBook;
}

ContactBook Contact::getContactBookByValue()
{
	return *contactBook;
}

void Contact::setName(const std::string& newName)
{
	name = newName;
}

void Contact::setNumber(const std::string& newNumber)
{
	number = newNumber;
}

void Contact::setContactBook(std::shared_ptr<ContactBook> newContactBook)
{
	contactBook = newContactBook;
}


