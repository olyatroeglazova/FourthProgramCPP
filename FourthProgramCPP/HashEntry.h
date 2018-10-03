#ifndef HASHENTRY_H
#define HASHENTRY_H


#include <iostream>
#include <string>
 
class HashEntry {
private:
	HashEntry* next;
	std::string key;
	double value;
public:
	HashEntry(std::string key, double value) {
		this->key = key;
		this->value = value;
		this->next = nullptr;
	}

	HashEntry(HashEntry& entry) {
		this->key = entry.key;
		this->value = entry.value;
		this->next = entry.next;
	}

	~HashEntry() {
		if (this->next != nullptr) delete this->next;
	}

	std::string getKey() {
		return key;
	}

	double getValue() {
		return value;
	}

	void setValue(double value) {
		this->value = value;
	}

	HashEntry *getNext() {
		return next;
	}

	void setNext(HashEntry *next) {
		this->next = next;
	}

	friend std::ostream &operator<<(std::ostream &os, HashEntry &element) {
		os << "{" << element.key << ", " << element.value << "}";
		return os;
	}
};


#endif;