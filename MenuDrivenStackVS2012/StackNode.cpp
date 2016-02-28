// Programmer Name: Kevin Vu

// Date: 7/23/2015
// Purpose: Compare the implementation of Lists, Queues, and Stacks


#ifndef STACKNODE_CPP
#define STACKNODE_CPP

#include "StackNode.h"

namespace Stacks 
{
	template <class Object>
	StackNode<Object>::StackNode( const Object& theElement,  StackNode<Object> * node ) 
	{
		element = theElement;
		next = node;
	}

	template <class Object>
	const Object& StackNode<Object>::getElement() const
	{
		return( element );
	}

	template <class Object>
	StackNode<Object>* StackNode<Object>::getNext() const
	{
		return( next );
	}

	template <class Object>
	void StackNode<Object>::setNext( StackNode<Object>* node ) 
	{
		next = node;
	}

}

#endif