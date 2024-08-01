#pragma once

#include <iostream>
#include <list>

#include "Serializable.h"

class Contact;

class ContactBook : public Serializable {
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

	int getSize() const;

	void downloadInfo(const std::string& path) override;

	void uploadInfo(const std::string& path) const override;
};