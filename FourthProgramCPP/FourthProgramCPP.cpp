#include "stdafx.h"
#include "HashTable.h"
#include "Iterator.h"
#include <iostream>
int main() {
	HashTable *newTable = new HashTable();
	
	newTable->push("one", 15);
	newTable->push("two", 19);
	newTable->push("three", 6);
	newTable->push("four", 12.12);
	newTable->push("five", 44);
	newTable->push("six", 45);
	newTable->push("seven", 44);
	newTable->push("eight", 20);
	newTable->push("nine", 20);
	newTable->push("ten", 20);
	std::cout << *newTable << std::endl;

	newTable->remove("five");
	newTable->remove("ten");
	newTable->remove("one");

	std::cout << "After remove three elems: \n";

	std::cout << *newTable << std::endl;


	Iterator iterator(&*newTable);

	std::cout << iterator << std::endl;


	std::cout << "\n";

	HashEntry *search = newTable->find("nine");
	if (search) {
		std::cout << "search 'nine' - " << search->getValue() << std::endl;
	}
	std::cout << "isEmpty() - " << newTable->isEmpty() << std::endl;
	std::cout << "clear()" << std::endl;
	newTable->clear();
	std::cout << "isEmpty() - " << newTable->isEmpty() << std::endl;


	system("pause");
	return 0;
}