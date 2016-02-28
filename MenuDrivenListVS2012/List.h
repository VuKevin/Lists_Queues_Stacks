// Programmer Name: Kevin Vu
// 
// Date: 7/23/2015
// Purpose: Compare the implementation of Lists, Queues, and Stacks

#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "ListNode.h"
#include "ListIterator.h"

namespace Lists 
{
	template <class Object>
	class List 
	{
		public:
			List(); // Constructor
			List( const List& rhs ); // Copy Constructor
			~List(); // Destructor

			bool isEmpty() const; // is the List empty?
			void makeEmpty(); // make the List empty
			ListIterator<Object> zeroth() const; // zeroth
			ListIterator<Object> first() const; // first
			void insert( const Object& data, const ListIterator<Object> &iter ); // insert
			void insert( const Object& data ); // insert
			ListIterator<Object> findPrevious( const Object& data ) const; // find the previous
			void remove( const Object& data ); // remove data
	
			const List& operator =( const List& rhs ); //Assignment operator

		// ASSIGNED:
			void insert(const List<Object> &list); // combine two lists
			void insertEnd(const Object& data);
			void sort(); // low to high sort 
			void sortD();
			// void sort(bool(*comparator)(Object &a, Object &b)); // EC: high to low sort


		private:
			ListNode<Object> * head; // head 
	};
}
#endif