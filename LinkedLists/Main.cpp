#include <iostream>
#include "Queue.h"
#include "LinkedList.h"
using namespace std; 

int main() {
	Queue<int> original = Queue<int>();
	original.insertBack(1);
	original.insertBack(2); 

	Queue<int> copy = Queue<int>();
	copy.insertBack(21235);

	copy = original; 

	return 0; 
}