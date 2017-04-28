#include <iostream>
#include "LinkedList.h"

using namespace std; 

int main() {
	LinkedList<int> myList = LinkedList<int>();
	myList.insertBack(12);
	cout << myList[-41];

	return 0; 
}