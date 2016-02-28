// Programmer Name: Kevin Vu
// 
// Date: 7/23/2015
// Purpose: Compare the implementation of Lists, Queues, and Stacks

#include "BadIterator.h"

namespace Lists 
{

	BadIterator::BadIterator( const std::string& msg ) 
		: std::logic_error( msg.c_str() ) 
	{}

}
