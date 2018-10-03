#ifndef ITERATOR_H
#define ITERATOR_H

#include "HashEntry.h"

class Iterator {

	HashTable *hashTable;
	int currentCell;
	HashEntry *currentHashEntry;

public:
	Iterator(HashTable *hashTable) : hashTable(hashTable) {
		start();
	}

	void start() {
		currentCell = 0;
	}

	HashEntry *next() {
		return currentHashEntry;
	}

	bool hasNext() {
		if (currentCell < hashTable->size()) {
			if(currentCell !=0) {
				currentHashEntry = currentHashEntry->getNext();
				if (currentHashEntry != nullptr) {
					return true;
				}
				currentCell++;
			}
			while (currentCell < hashTable->size()) {
				currentHashEntry = hashTable->table[currentCell];
				if (currentHashEntry != nullptr) {
					return true;
				}
				currentCell++;
			}
		}
		return false;
	}

	friend std::ostream &operator<<(std::ostream &os, Iterator &element) {
		element.start();
		os << "Iterator";
		while (element.hasNext()) {
			os << "\n" <<  *element.next();
		}
		return os;
	}
};

#endif