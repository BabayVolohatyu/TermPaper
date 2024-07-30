#include "ContactBook.h"
#include "Contact.h"

ContactBook* ContactBook::instancePtr = nullptr;

ContactBook::ContactBook()
	:contacts{} {}

ContactBook::~ContactBook() {
	delete instancePtr;
	instancePtr = nullptr;
}

ContactBook* ContactBook::getInstance() {
	if (!instancePtr) {
		instancePtr = new ContactBook;
		return instancePtr;
	}
	else return instancePtr;
}

void ContactBook::emplace_front(Contact&& contact) {
	contacts.emplace_front(std::move(contact));
}

void ContactBook::emplace_back(Contact&& contact) {
	contacts.emplace_back(std::move(contact));
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