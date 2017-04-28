#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
struct Node {
	T data;
	Node<T>* next;
};

template <class T>
class LinkedList {
protected:
	Node<T>* head;
	int nodeCount;
public:
	LinkedList();
	~LinkedList();
	void destroy();
	int getNodeCount();
	void insertFront(T);
	void insertBack(T);
	void deleteBack();
	void deleteFront();
	T& operator[](int);
	void operator=(LinkedList<T>);
};

template <class T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	nodeCount = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
	destroy();
}

template <class T>
void LinkedList<T>::destroy() {
	while (nodeCount > 0)
		deleteFront();
}

template <class T>
int LinkedList<T>::getNodeCount() { return nodeCount; }

template <class T>
void LinkedList<T>::insertFront(T data) {
	Node<T>* newNode = new Node<T>;
	if (nodeCount == 0)
		newNode->next = nullptr;
	else
		newNode->next = head;
	newNode->data = data;
	head = newNode;
	nodeCount++;
}

template <class T>
void LinkedList<T>::insertBack(T data) {
	Node<T>* newNode = new Node<T>;
	if (nodeCount < 1) {
		head = newNode;
	}
	else {
		Node<T>* iterator = head;
		while (iterator->next != nullptr) {
			iterator = iterator->next;
		}
		iterator->next = newNode;
	}
	newNode->data = data;
	newNode->next = nullptr;
	nodeCount++;
}

template <class T>
void LinkedList<T>::deleteFront() {
	if (nodeCount < 1) return;
	Node<T>* nodeToDelete = head;
	head = head->next;
	nodeToDelete->next = nullptr;
	delete nodeToDelete;
	nodeCount--;
}

template <class T>
void LinkedList<T>::deleteBack() {
	if (nodeCount < 1) {
		return;
	}
	else if (nodeCount == 1)
	{
		delete head;
		head = nullptr;
	}
	else {
		Node<T>* iterator = head;
		Node<T>* lastNode = head;
		while (iterator->next != nullptr) {
			lastNode = iterator;
			iterator = iterator->next;
		}
		delete iterator;
		lastNode->next = nullptr;
	}
	nodeCount--;
}

template <class T>
T& LinkedList<T>::operator[](int index) {
	if (index < 0 || index > nodeCount - 1)
		throw std::out_of_range("Index is out of bounds.");

	Node<T>* iterator = head;
	for (int i = 0; i < index; i++)
	{
		iterator = iterator->next;
	}
	return iterator->data;
}

template <class T>
void LinkedList<T>::operator=(LinkedList<T> listToCopy) {
	for (int i = 0; i < listToCopy.nodeCount; i++) {
		insertBack(listToCopy[i]);
	}
	this->nodeCount = listToCopy.getNodeCount();
}

#endif