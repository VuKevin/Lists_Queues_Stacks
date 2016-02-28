// Programmer Name: Kevin Vu
// 
// Date: 7/23/2015
// Purpose: Compare the implementation of Lists, Queues, and Stacks

#ifndef LISTITERATOR_CPP
#define LISTITERATOR_CPP

#include "ListIterator.h"

namespace Lists 
{
	template <class Object>
	ListIterator<Object>::ListIterator()
		: current( NULL )  
	{
		// all assignments occurred above
	}

	template <class Object>
	ListIterator<Object>::ListIterator( ListNode<Object> *node ) 
		: current( node ) 
	{
		// all assignments occurred above
	}

	template <class Object>
	bool ListIterator<Object>::isValid( ) const // are you currently at a nullptr?
	{
		return( (current != NULL) );
	}


	template <class Object>
	void ListIterator<Object>::advance( ) // Traverse
	{
		if (isValid()) 
			current = current->getNext();
	}

	template <class Object>
	const Object& ListIterator<Object>::retrieve( ) const // Retrieve the data element
	{
		if (!(isValid()))  // If current holds a nullptr
			throw BadIterator(); 
		return( current->getElement() );
	}
}

#endif