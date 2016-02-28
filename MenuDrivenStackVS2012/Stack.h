// Programmer Name: Kevin Vu

// Date: 7/23/2015
// Purpose: Compare the implementation of Lists, Queues, and Stacks

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "StackNode.h"
#include "EmptyStack.h"

namespace Stacks 
{
	template <class Object>
	class Stack 
	{
		public:
			Stack();
			Stack( const Stack& rhs );
			~Stack();

			bool isEmpty() const;
			void makeEmpty();
			void push( const Object& data );
			void pop();
			const Object& top() const;
			Object topAndPop();
			std::ostream& printStack( std::ostream& outs ) const;
	
			const Stack& operator =( const Stack& rhs );

			// ASSIGNED:
			bool isConsecutive(const Object &data) const;
			void Stack<Object>::reverse();

		private:
			StackNode<Object> * topNode;
	};
}

#endif