// Nigel A. Smith
#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"

template <class T>
class Queue
{
protected:
	LinkedList<T> list;

public:
	Queue();
	~Queue();
	void insertBack(T);
	T peekFront();
	T popFront();
	int getNodeCount() const;
	bool isEmpty() const;
	void destroy();
	void operator=(const Queue<T>&);
};

template <class T>
Queue<T>::Queue()
{
	list = LinkedList<T>();
}

template <class T>
Queue<T>::~Queue()
{
	destroy();
}

template <class T>
void
Queue<T>::insertBack(T insertionData)
{
	list.insertBack(insertionData);
}

template <class T>
T
Queue<T>::peekFront()
{
	if (list.getNodeCount() == 0)
		throw "The queue is empty. Cannot peek.";
	return list[0];
}

template <class T>
T
Queue<T>::popFront()
{
	if (list.getNodeCount() == 0)
		throw "The queue is empty. Cannot pop.";
	T frontValue = list[0];
	list.deleteFront();
	return frontValue;
}

template <class T>
void
Queue<T>::destroy()
{
	list.destroy();
}

template <class T>
int
Queue<T>::getNodeCount() const
{
	return list.getNodeCount();
}

template <class T>
bool
Queue<T>::isEmpty() const
{
	return this->getNodeCount() == 0;
}

template <class T>
void Queue<T>::operator=(const Queue<T>& queueToCopy)
{
	this->list = queueToCopy.list;
}
#endif