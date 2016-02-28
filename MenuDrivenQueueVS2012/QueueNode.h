// Programmer Name: Kevin Vu

// Date: 7/23/2015
// Purpose: Compare the implementation of Lists, Queues, and Stacks

#ifndef QUEUENODE_H
#define QUEUENODE_H
#include <iostream>

namespace Queues 
{
	template <class Object>
	class QueueNode
	{
		public:
			QueueNode( const Object& theElement = Object(), QueueNode * node = NULL );

			// these accessors and mutators are called
			// from Queue class
			// no public methods expose QueueNode instances
			// outside the Queue class
			const Object& getElement() const;
			QueueNode* getNext() const;
			void setNext( QueueNode * node );

		private:
			Object element;
			QueueNode* next;

	};
}
#endif