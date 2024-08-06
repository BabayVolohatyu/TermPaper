#pragma once

#include <iostream>
#include <list>

#include "Serializable.h"

class Contact;

class ContactBook : public Serializable {
private:
	std::list<Contact> contacts;

	static ContactBook* contactBook;

	ContactBook();

public:

	ContactBook(const ContactBook& other) = delete;

	~ContactBook();

	static ContactBook* getInstance();

	/*метод deleteInstance() має викликатися виключно з об'єкту Account для 
	запобіганню проблем з алокацією та деаолкацією пам'яті'*/
	void deleteInstance();

	void emplace_front(Contact&& contact);

	void emplace_front(const Contact& contact);

	void emplace_back(Contact&& contact);

	void emplace_back(const Contact& contact);

	void pop_front();

	void pop_back();

	void insert(int id, Contact&& contact);

	void erase(int id);

	int getSize() const;

	void getDataFromObject(std::ostream& os) const override;

	void setDataToObject(std::istream& is) override;
};