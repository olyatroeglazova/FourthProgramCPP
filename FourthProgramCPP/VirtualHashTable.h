#ifndef VIRTUALHASHTABLE_H
#define VIRTUALHASHTABLE_H

#include "HashEntry.h"
#include <iostream>
#include <string>

class VirtualHashTable {
public:

	static const int SIZE = 256;
	HashEntry *table[SIZE];

	virtual void push(std::string key, double value) = 0;

	virtual HashEntry *find(std::string key) = 0;

	virtual void remove(std::string key) = 0;

	virtual void clear() = 0;

	virtual bool isEmpty() = 0;

	int size() {
		return SIZE;
	}

	friend std::ostream &operator<<(std::ostream &os, VirtualHashTable &table) {
		for (int i = 0; i < SIZE; i++) {
			if (table.table[i] != nullptr) {
				os << "Cell " << i;

				HashEntry *entry = table.table[i];
				while (entry != nullptr) {
					os << (entry == table.table[i] ? ": " : ", ") << *entry;
					entry = entry->getNext();
				}
				os << "\n";
			}
		}
		return os;
	}

};

#endif