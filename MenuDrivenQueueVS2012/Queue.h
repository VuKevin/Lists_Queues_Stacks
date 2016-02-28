// Programmer Name: Kevin Vu

// Date: 7/23/2015
// Purpose: Compare the implementation of Lists, Queues, and Stacks

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "QueueNode.h"
#include "EmptyQueue.h"

namespace Queues
{
	template <class Object>
	class Queue {
	public:
		Queue();
		Queue( const Queue& rhs );
		~Queue();

		bool isEmpty() const;
		void makeEmpty();
		void enqueue( const Object& data );
		const Object dequeue();
		const Object& getFront() const;
	
		const Queue& operator =( const Queue& rhs );

		std::ostream& printQueue( std::ostream& outs );

		// ASSIGNED: 
		int count(const Object & data) const;
		bool isDecreasing() const;

	private:
		QueueNode<Object> * frontNode;
		QueueNode<Object> * backNode;
	};
}
#endif