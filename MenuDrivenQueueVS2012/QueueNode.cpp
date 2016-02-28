// Programmer Name: Kevin Vu

// Date: 7/23/2015
// Purpose: Compare the implementation of Lists, Queues, and Stacks

#ifndef QUEUENODE_CPP
#define QUEUENODE_CPP

#include "QueueNode.h"

namespace Queues 
{
	template <class Object>
	QueueNode<Object>::QueueNode( const Object& theElement,
								  QueueNode<Object> * node ) {
		element = theElement;
		next = node;
	}

	template <class Object>
	const Object& QueueNode<Object>::getElement() const {
		return( element );
	}

	template <class Object>
	QueueNode<Object>* QueueNode<Object>::getNext() const {
		return( next );
	}

	template <class Object>
	void QueueNode<Object>::setNext( QueueNode<Object> * node ) {
		next = node;
	}
}

#endif