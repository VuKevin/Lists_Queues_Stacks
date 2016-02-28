// Programmer Name: Kevin Vu
// 
// Date: 7/23/2015
// Purpose: Compare the implementation of Lists, Queues, and Stacks

#ifndef BADITERATOR_H
#define BADITERATOR_H
#include <iostream>
#include <string>

namespace Lists 
{
	class BadIterator : public std::logic_error 
	{
		public:
			BadIterator( const std::string& msg = "" );
	};
}

#endif