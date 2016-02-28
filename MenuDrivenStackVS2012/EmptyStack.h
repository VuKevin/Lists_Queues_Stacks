// Programmer Name: Kevin Vu

// Date: 7/23/2015
// Purpose: Compare the implementation of Lists, Queues, and Stacks

#ifndef EMPTYSTACK_H
#define EMPTYSTACK_H
#include <iostream>
#include <string>

namespace Stacks 
{
	class EmptyStack : public std::logic_error 
	{
		public:
			EmptyStack( const std::string& msg = "" )
				:std::logic_error(msg.c_str())
			{}
	};
}
#endif