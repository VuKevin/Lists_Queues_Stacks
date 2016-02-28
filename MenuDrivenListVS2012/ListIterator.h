// Programmer Name: Kevin Vu
// 
// Date: 7/23/2015
// Purpose: Compare the implementation of Lists, Queues, and Stacks

#ifndef LISTITERATOR_H
#define LISTITERATOR_H
#include <iostream>
#include "ListNode.h"
#include "BadIterator.h"

namespace Lists 
{

template <class Object>
class List;					// forward declaration

template <class Object>
class ListIterator 
{
	public:
		ListIterator(); // Constructor
		bool isValid() const; // If the current node is still valid to be iterated through (is not a NULLptr)
		void advance(); // Traverser
		const Object& retrieve() const; // Accessor
	
	private:
		ListNode<Object> *current; // current pointer
	
		ListIterator( ListNode<Object> *node );

		// List exposes ListIterator instances via public methods
		// no external access should be given to the current pointer
		// friend access is required by List class to ensure this information hiding
		friend class List<Object>;
};

}
#endif