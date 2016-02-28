// Programmer Name: Kevin Vu
// 
// Date: 7/23/2015
// Purpose: Compare the implementation of Lists, Queues, and Stacks

#ifndef LIST_CPP
#define LIST_CPP

#include "List.h"
#include <iostream>
namespace Lists
{
	template <class Object>
	List<Object>::List() // Constructor
	{
		head = new ListNode<Object>; // head points to a newly created, dynamically allocated Node
	}

	template <class Object>
	List<Object>::List(const List<Object>& rhs) // Copy Constructor
	{
		head = new ListNode<Object>; // head points to a newly created, dynamically allocated Node
		*this = rhs;				// the current object being called upon gets the address of the original
	}

	template <class Object> // Destructor
	List<Object>::~List()
	{
		makeEmpty(); // Makes the linked list empty 
		delete head; // Frees the dynamically allocated pointer head
	}

	template <class Object>
	bool List<Object>::isEmpty() const  // Checks whether the linked list is empty
	{
		return(head->nextIsNull());
	}

	template <class Object>
	void List<Object>::makeEmpty()  // Make empty fxn
	{
		while (!isEmpty())
			remove(first().retrieve());
	}

	template <class Object>
	ListIterator<Object> List<Object>::zeroth() const // returns the head data member
	{
		return(ListIterator<Object>(head));
	}

	template <class Object>
	ListIterator<Object> List<Object>::first() const // returns the first data member
	{
		return(ListIterator<Object>(head->getNext()));
	}

	template <class Object>
	void List<Object>::insert(const Object& data, const ListIterator<Object> &iter) // INSERT: At a location
	{
		if (iter.isValid())
		{
			ListNode<Object>* newnode = new ListNode<Object>(data, iter.current->getNext());
			iter.current->setNext(newnode);
		}
	}

	template <class Object>
	void List<Object>::insert(const Object& data) // INSERT: After the header node in the beg
	{
		// insert after the header node
		ListNode<Object>* newnode = new ListNode<Object>(data, head->getNext());
		head->setNext(newnode);
	}

	template <class Object>
	ListIterator<Object> List<Object>::findPrevious(const Object& data) const  // Find's the previous node before the data value
	{
		ListNode<Object>* node = head; // Creates an pointer, node, that holds the address of head
		while (node->getNext() != NULL && node->getNext()->getElement() != data) // Loop
			node = node->getNext();
		if (node->getNext() == NULL)
			node = NULL;
		return ListIterator<Object>(node);
	}

	template <class Object>
	void List<Object>::remove(const Object& data) // removes data 
	{
		ListIterator<Object> iter = findPrevious(data); // iter points to the node that has the data
		if (iter.isValid())
		{
			ListNode<Object>* node = findPrevious(data).current; // node points to the node that has the data
			if (node->getNext() != NULL)  // if it's not the end of the list
			{
				ListNode<Object> *oldNode = node->getNext(); // creates a pointer, oldNode, that hold's the address of node's next
				node->setNext(node->getNext()->getNext());  // Skip oldNode [have the previous node point to the next next node (2 nodes down)]
				delete oldNode; // delete the node with the data value
			}
		}
	}

	// Deep copy of linked list
	template <class Object>
	const List<Object>& List<Object>::operator =(const List<Object>& rhs) // Assignment operator: Destructor + CC
	{
		if (this != &rhs)
		{
			makeEmpty();

			ListIterator<Object> rightiter = rhs.first();
			ListIterator<Object> myiterator = zeroth();
			while (rightiter.isValid())
			{
				insert(rightiter.retrieve(), myiterator); // starting at the 0th, insert
				rightiter.advance(); // increment to the next
				myiterator.advance(); // increment to the next
			}
			// added
			return (*this);
		}
		else // they are the same object
			return(*this);
	}

	//
	// ASSIGNED:
	//

	template<class Object>
	void List<Object>::insert(const List<Object>& list) // Merge two lists: #1
	{
		// Representation: Parameter list is appended to the back of the calling list
		int thisSize = 0;
		ListNode<Object> *retrieveSize = head;
		while (retrieveSize->getNext() != NULL) // Retrieve size of calling list
		{
			thisSize++;
			retrieveSize = retrieveSize->getNext();
		}

		int listSize = 0;
		ListNode<Object> *retrieveListSize = list.head;
		while (retrieveListSize->getNext() != NULL) // Retrieve size of parameter list
		{
			listSize++;
			retrieveListSize = retrieveListSize->getNext();
		}
		const int constSize = thisSize + listSize;

		Object *oPtr = new Object[constSize]; // Dynamicaly allocate an array to hold elements of DataType enough for both lists
		ListNode<Object> *thisPtr = head; 
		int k = 0;
		while (thisSize > 0) // Copy elements of this list to array
		{
			oPtr[k] = thisPtr->getNext()->getElement();
			k++;
			thisSize--;
			thisPtr = thisPtr->getNext();
		}
		ListNode<Object> *listPtr = list.head;
		int j = k;
		while (listSize > 0)
		{
			oPtr[j] = listPtr->getNext()->getElement();
			j++;
			listSize--;
			listPtr = listPtr->getNext();
		}

		// Make empty
		makeEmpty();
		// xFer to list
		int size2 = constSize;
		int index = size2 -1;
		while (size2 > 0)
		{
			insert(oPtr[index]);
			index--;
			size2--;
		}
		delete[] oPtr;
	}

	template <class Object>
	void List<Object>::insertEnd(const Object& data) // INSERT: At the end! Excercise for fun.
	{
		ListNode<Object>* newnode = new ListNode<Object>(data, NULL);
		if (head == NULL)
			head = newnode;
		ListNode<Object> *getToEnd = head;
		while (getToEnd->getNext() != nullptr)
			getToEnd = getToEnd->getNext();
		getToEnd->setNext(newnode);
	}

	template<class Object>
	void List<Object>::sort() // ASCENDING SORT: #2
		// Method&Representation: Changed data elements to sort.
		// Alternative method with swapping the pointers: http://puu.sh/j9CQl/10963c0c3b.png
	{
		int size = 0;
		ListNode<Object> *retrieveSize = head;
		while (retrieveSize->getNext() != NULL) // Get the size of the linked list
		{
			size++;
			retrieveSize = retrieveSize->getNext();
		}
		Object *oPtr = new Object[size]; // Dynamicaly allocate an array to hold elements of DataType
		ListNode<Object> *ptr = head;
		int k = 0;
		int sizeCopy = 0;
		while (size > 0)  // Copy the elements to a seperate list
		{
			oPtr[k] = ptr->getNext()->getElement();
			k++;
			size--;
			sizeCopy++;
			ptr = ptr->getNext();
		}

		Object *a = &oPtr[0]; // Sort the seperate list
		Object *b = &oPtr[0];
		int aIndex = 0;
		int bIndex = 1;
		const int constSize = sizeCopy; // keep a constant size of list to reference
		int sizeTracker = constSize;
		int v = 1;
		while (sizeCopy > 0)
		{
			while (sizeTracker > 1 && bIndex != constSize)
			{
				if (a[aIndex] > b[bIndex]) // if the left side is greater than the right side
				{
					Object temp[2];
					temp[0] = a[aIndex]; // holds the left side;
					temp[1] = b[bIndex]; // holds the right side;
					oPtr[aIndex] = temp[1]; // give the left side the right side;
					oPtr[bIndex] = temp[0]; // give the right side the left side;
				}
				bIndex++;
				sizeTracker--;
			}
			sizeTracker = constSize;
			sizeCopy--;
			aIndex++;
			bIndex = 1;
			bIndex = bIndex + v;
			v++;
		}


		int retainedSize = constSize;
		makeEmpty(); // Clear the list
		int x = retainedSize - 1;
		ListNode<Object> *xferSorted = head;	// Copy over sorted list to original list.
		while (retainedSize > 0)
		{
			retainedSize--;
			this->insert(oPtr[x]);
			x--;
		}
		delete [] oPtr;
	}

	//template<class Object>
	//void List<Object>::sort(bool(*comparator)(Object &a, Object &b)) // Extra Credit Problem
	//{
	//}

	template<class Object>
	void List<Object>::sortD() // DESCENDING SORT: 
	 // Method&Representation: Changed data elements to sort.
	{
		int size = 0;
		ListNode<Object> *retrieveSize = head;
		while (retrieveSize->getNext() != NULL) // Get the size of the linked list
		{
			size++;
			retrieveSize = retrieveSize->getNext();
		}
		Object *oPtr = new Object[size]; // Dynamicaly allocate an array to hold elements of DataType
		ListNode<Object> *ptr = head;
		int k = 0;
		int sizeCopy = 0;
		while (size > 0)  // Copy the elements to a seperate list
		{
			oPtr[k] = ptr->getNext()->getElement();
			k++;
			size--;
			sizeCopy++;
			ptr = ptr->getNext();
		}

		Object *a = &oPtr[0]; // Sort the seperate list
		Object *b = &oPtr[0];
		int aIndex = 0;
		int bIndex = 1;
		const int constSize = sizeCopy; // keep a constant size of list to reference
		int sizeTracker = constSize;
		int v = 1;
		while (sizeCopy > 0)
		{
			while (sizeTracker > 1 && bIndex != constSize)
			{
				if (a[aIndex] < b[bIndex]) // if the left side is less than the right side
				{
					Object temp[2];
					temp[0] = a[aIndex]; // holds the left side;
					temp[1] = b[bIndex]; // holds the right side;
					oPtr[aIndex] = temp[1]; // give the left side the right side;
					oPtr[bIndex] = temp[0]; // give the right side the left side;
				}
				bIndex++;
				sizeTracker--;
			}
			sizeTracker = constSize;
			sizeCopy--;
			aIndex++;
			bIndex = 1;
			bIndex = bIndex + v;
			v++;
		}

		int retainedSize = constSize;
		makeEmpty(); // Clear the list
		int x = retainedSize - 1;
		ListNode<Object> *xferSorted = head;	// Copy over sorted list to original list.
		while (retainedSize > 0)
		{
			retainedSize--;
			this->insert(oPtr[x]);
			x--;
		}
		delete[] oPtr;
	}
}

#endif