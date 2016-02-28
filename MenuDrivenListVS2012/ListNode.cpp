// Programmer Name: Kevin Vu
// 
// Date: 7/23/2015
// Purpose: Compare the implementation of Lists, Queues, and Stacks

#ifndef LISTNODE_CPP
#define LISTNODE_CPP

#include "ListNode.h"

namespace Lists 
{
	template <class Object>
	ListNode<Object>::ListNode( const Object& theElement, ListNode<Object> * node )
	{
		element = theElement;
		next = node;
	}

	template <class Object>
	bool ListNode<Object>::nextIsNull() const
	{
		return( next == NULL );
	}

	template <class Object>
	const Object& ListNode<Object>::getElement() const 
	{
		return( element );
	}

	template <class Object>
	ListNode<Object>* ListNode<Object>::getNext() const
	{
		return( next );
	}

	template <class Object>
	void ListNode<Object>::setNext( ListNode<Object> * node ) 
	{
		next = node;
	}
}

#endif