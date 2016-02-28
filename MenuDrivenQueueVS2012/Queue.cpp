// Programmer Name: Kevin Vu

// Date: 7/23/2015
// Purpose: Compare the implementation of Lists, Queues, and Stacks

#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"

namespace Queues 
{
	// ASSIGNED:
	template <class Object>
	int Queue<Object>::count(const Object &data) const
	{
		int count = 0;
		QueueNode<Object> *ptr = frontNode;
		while (ptr != NULL)
		{
			if (ptr->getElement() == data)
				count = count + 1;
			ptr = ptr->getNext();
		}
		return count;
	}
	template <class Object>
	bool Queue<Object>::isDecreasing() const
	{
		QueueNode<Object> *retrieveSize = frontNode;
		int size = 0;
		while (retrieveSize != NULL)
		{
			size++;
			retrieveSize = retrieveSize->getNext();
		}
		if (size == 1) // If it's a list of size 1, I decided to consider that as notDecreasing
			return false;
		QueueNode<Object> *ptr = frontNode;
		QueueNode<Object> *ptr2 = frontNode->getNext();
		while (ptr2 != NULL)
		{
			if (ptr->getElement() < ptr2->getElement()) // if the lhs is less than the rhs
			{
				return false; 
			}
			// advance
			ptr = ptr->getNext();
			ptr2 = ptr2->getNext();
		}
		return true;
	}

	template <class Object>
	Queue<Object>::Queue() 
	{
		frontNode = NULL;
		backNode = NULL;
	}

	template <class Object>
	Queue<Object>::Queue( const Queue<Object>& rhs )
	{
		frontNode = NULL;
		backNode = NULL;
		*this = rhs;
	}

	template <class Object>
	Queue<Object>::~Queue() {
		makeEmpty();
		// when empty, frontNode and backNode will already be null
	}

	template <class Object>
	bool Queue<Object>::isEmpty() const
	{
		return( (frontNode == NULL) );
	}

	template <class Object>
	void Queue<Object>::makeEmpty()
	{
		while (!isEmpty()) {
			dequeue();
		}
	}

	template <class Object>
	void Queue<Object>::enqueue( const Object& data ) 
	{
		QueueNode<Object>* newNode = new QueueNode<Object>( data );
		if (isEmpty()) {
			frontNode = newNode;
			backNode = newNode;
		}
		else {
			backNode->setNext( newNode );
			backNode = backNode->getNext();
		}
	}

	template <class Object>
	const Object Queue<Object>::dequeue()
	{
		Object frontData = getFront();

		QueueNode<Object> * oldFront = frontNode;
		frontNode = frontNode->getNext();
		delete oldFront;
		return( frontData );
	}

	template <class Object>
	const Object& Queue<Object>::getFront() const 
	{
		if (isEmpty()) {
			throw EmptyQueue();
		}
		return( frontNode->getElement() );
	}

	// Deep copy of linked Queue
	template <class Object>
	const Queue<Object>& Queue<Object>::operator =( const Queue<Object>& rhs )
	{
		if (this != &rhs) {
			makeEmpty();
			QueueNode<Object> * rhsFrontNode = rhs.frontNode;
			while( rhsFrontNode != NULL) {
				enqueue( rhsFrontNode->getElement() );
				rhsFrontNode = rhsFrontNode->getNext();
			}
		}
		return( *this );
	}

	template <class Object>
	std::ostream& Queue<Object>::printQueue( std::ostream& outs )
	{
		if (isEmpty()) {
			outs << "Empty Queue";
		}
		else {
			outs << "FRONT: ";
			QueueNode<Object> * node = frontNode;
			while( node != NULL) {
				outs << node->getElement();
				outs << " ";
				node = node->getNext();
			}
			outs << ":BACK";
		}
		return( outs );
	}
	
}
#endif