#include <string>

#include "../Headers/ContactBook.h"
#include "../Headers/Contact.h"

ContactBook* ContactBook::contactBook = nullptr;

ContactBook::ContactBook()
	:contacts{} {}

ContactBook::~ContactBook() = default;

ContactBook* ContactBook::getInstance() {
	if (!contactBook) {
		contactBook = new ContactBook();
		return contactBook;
	}
	else return contactBook;
}

void ContactBook::deleteInstance() {
	delete contactBook;
	contactBook = nullptr;
}

void ContactBook::emplace_front(Contact&& contact) {
	contacts.emplace_front(std::move(contact));
}

void ContactBook::emplace_front(const Contact& contact){
	contacts.emplace_front(contact);
}

void ContactBook::emplace_back(Contact&& contact) {
	contacts.emplace_back(std::move(contact));
}

void ContactBook::emplace_back(const Contact& contact){
	contacts.emplace_back(contact);
}

void ContactBook::pop_front() {
	contacts.pop_front();
}

void ContactBook::pop_back() {
	contacts.pop_back();
}

void ContactBook::insert(int id, Contact&& contact) {
	std::list<Contact>::iterator it = contacts.begin();
	std::advance(it, id);
	try {
		contacts.insert(it, contact);
	}
	catch (...) {
		return;
	}
}

void ContactBook::erase(int id) {
	std::list<Contact>::iterator it = contacts.begin();
	std::advance(it, id);
	try {
		contacts.erase(it);
	}
	catch (...) {
		return;
	}
	
}

int ContactBook::getSize() const {
	return contacts.size();
}

Contact ContactBook::getContactById(int id) {
	if (id < 0 || id >= contacts.size()) {
		throw std::out_of_range("Invalid index");
	}

	std::list<Contact>::iterator it = contacts.begin();
	std::advance(it, id);
	return *it;
}


void ContactBook::getDataFromObject(std::ostream& os) const{
	os << contacts.size() << std::endl;
	for (std::list<Contact>::const_iterator it = contacts.begin(); it != contacts.end();it++) {
		it->getDataFromObject(os);
	}
}

void ContactBook::setDataToObject(std::istream& is){
	std::string currentLine;
	std::getline(is, currentLine);
	int numberOfContacts = 0;
	try {
		numberOfContacts = std::stoi(currentLine);
	}
	catch (...) {
		return;
	}
	for (int i = 0; i < numberOfContacts;i++) {
		Contact newContact;
		newContact.setDataToObject(is);
		contactBook->emplace_back(newContact);
	}
}

