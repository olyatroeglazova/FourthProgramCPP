#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "HashEntry.h"
#include "VirtualHashTable.h"
#include <string>

class HashTable : public VirtualHashTable {

	int hash(std::string key) {
		int t=0;
		for (int i = 0; i<key.size(); i++) {
			t += key[i];
		}
		return t % SIZE;
	}

public:

	HashTable() {
		for (int i = 0; i < SIZE; i++) {
			table[i] = nullptr;
		}
	}

	~HashTable() {
		clear();
	}

	HashEntry *find(std::string key) {
		int H = hash(key);
		HashEntry *result = table[H];
		while (result != nullptr && result->getKey() != key) {
			result = result->getNext();
		}
		return result;
	}

	void push(std::string key, double value) {
		HashEntry *entry = find(key);
		if (entry == nullptr) {
			int H = hash(key);
			HashEntry *tmp = new HashEntry(key, value);
			HashEntry *place = table[H];
			if (place == nullptr) {
				table[H] = tmp;
			}
			else {
				while (place->getNext() != nullptr) {
					place = place->getNext();
				}
				place->setNext(tmp);
			}
		}
		else {
			entry->setValue(value);
		}
	}


	void remove(std::string key) {
		HashEntry *entry = find(key);
		if (entry == nullptr)
			return;
		else {
			if (entry == table[hash(key)]) {
				table[hash(key)] = entry->getNext();
			}
			else {
				HashEntry *res = table[hash(key)];
				HashEntry *tmp = table[hash(key)];
				while (tmp->getNext() != entry) {
					res->setNext(tmp);
				}
				res->setNext(entry->getNext());
				delete entry;
				table[hash(key)] = res;
			}
		}
	}

	void clear() {
		for (int i = 0; i < SIZE; i++) {
			delete table[i];
			table[i] = nullptr;
		}
	}

	bool isEmpty() {
		for (int i = 0; i < SIZE; i++) {
			if (table[i] != nullptr)
				return false;
		}
		return true;
	}


};

#endif