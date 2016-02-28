// Programmer Name: Kevin Vu

// Date: 7/23/2015
// Purpose: Compare the implementation of Lists, Queues, and Stacks

#ifndef STACKNODE_H
#define STACKNODE_H
#include <iostream>

namespace Stacks
{
	template <class Object>
		class StackNode 
		{
			public:
				StackNode( const Object& theElement = Object(), StackNode * node = NULL );

				const Object& getElement() const;
				StackNode* getNext() const;
				void setNext( StackNode* node );
			private:
				Object element;
				StackNode* next;

		};
}
#endif