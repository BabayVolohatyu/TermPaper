#pragma once

#include <iostream>
#include <list>
#include <memory>

class Contact;

class ContactBook {
private:
	std::list<Contact> contacts;

	static ContactBook* instancePtr;

	ContactBook();

public:

	ContactBook(const ContactBook& other) = delete;

	~ContactBook();

	static ContactBook* getInstance();

	void emplace_front(Contact&& contact);

	void emplace_back(Contact&& contact);

	void pop_front();

	void pop_back();

	void insert(int id, Contact&& contact);

	void erase(int id);
};