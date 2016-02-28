// Programmer Name: Kevin Vu

// Date: 7/23/2015
// Purpose: Compare the implementation of Lists, Queues, and Stacks

#ifndef EMPTYQUEUE_H
#define EMPTYQUEUE_H
#include <iostream>
#include <string>

namespace Queues {

class EmptyQueue : public std::logic_error {
public:
	EmptyQueue( const std::string& msg = "" );
};

}
#endif