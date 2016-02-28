// Menu.cpp : Defines the entry point for the console application.
// Programmer Name: Kevin Vu

// Date: 7/23/2015
// Purpose: Compare the implementation of Lists, Queues, and Stacks

#include <iostream>
#include "Stack.h"
#include "EmptyStack.h"
#include "StackNode.h"
#include "Stack.cpp"
#include "StackNode.cpp"

using namespace std;
using namespace Stacks;

enum CHOICE {MAKEEMPTY, PUSH, ISEMPTY, POP, TOP, TOPANDPOP, QUIT, PRINT, CONSEC, REVERSE};

CHOICE menu();

int main(int argc, char* argv[]) {
	int value;
	Stack<int> stack;

	CHOICE choice;
	do {
		choice = menu();
		switch( choice ) {
		case MAKEEMPTY:
			stack.makeEmpty();
			break;
		case ISEMPTY:
			if (stack.isEmpty()) {
				cout << "stack is empty" << endl;
			}
			else {
				cout << "stack is not empty" << endl;
			}
			break;
		case TOP:
			try {
				value = stack.top();
				cout << "Here's the value on top: ";
				cout << value << endl;
			} catch( EmptyStack es ) {
				cout << "You silly... don't try topping an empty stack!" << endl;			
			}
			break;
		case POP:
			try {
				stack.pop();
			} catch( EmptyStack es ) {
				cout << "You silly... don't try popping an empty stack!" << endl;
			}
			break;
		case PUSH:
			cout << "Please provide int to push: ";
			cin  >> value; 
			stack.push( value );
			break;
		case TOPANDPOP:
			try {
				value = stack.topAndPop();
				cout << "Here's the value on top that got popped: ";
				cout << value << endl;
			} catch( EmptyStack es ) {
				cout << "You silly... don't try topAndPopping an empty stack!" << endl;
			}
			break;
		case PRINT:
			stack.printStack( cout );
			cout << endl;
			break;
		case CONSEC:
			cout << "Please provide an int to check for consec: ";
			cin >> value;
			if (stack.isConsecutive(value))
				cout << "Stack has consecutives of " << value << endl;
			else
				cout << "Stack does NOT have consecutives of value " << value << endl;
			break;
		case REVERSE:
			cout << "Reversing the list..." << endl;
			stack.reverse();
			break;
	}	

	} while (choice != QUIT);

	return( 0 );
}

CHOICE menu() {
	char choice;
	CHOICE result;
	cout << "(M)kEmpt I(s)Emt p(U)s p(O)p (T)p tp(A)ndpp (R)evrs (C)ons (P)rt (Q)uit: " << endl;
	cin  >> choice;
	switch( choice ) {
	case 'A':
	case 'a':
		result = TOPANDPOP;
		break;
	case 'M':
	case 'm':
		result = MAKEEMPTY;
		break;
	case 'S':
	case 's':
		result = ISEMPTY;
		break;
	case 'U':
	case 'u':
		result = PUSH;
		break;
	case 'O':
	case 'o':
		result = POP;
		break;
	case 'T':
	case 't':
		result = TOP;
		break;
	case 'Q':
	case 'q':
		result = QUIT;
		break;
	case 'c':
	case 'C':
		result = CONSEC;
		break;
	case 'P':
	case 'p':
		result = PRINT;
		break;
	case 'R':
	case 'r':
		result = REVERSE;
		break;

	}

	return( result );
}

void sample() {
	Stack<int> s1;
	Stack<int> s2;
	cout << "making s1" << endl;
	s1.push( 1 );
	s1.push( 2 );
	cout << "print s1" << endl;
	s1.printStack( cout );
	cout << endl;

	cout << "s2 = s1" << endl;

	s2 = s1;
	cout << "print s2" << endl;
	s2.printStack( cout );
	cout << endl;

	s1.pop();
	cout << "pop s1" << endl;

	cout << "print s2" << endl;
	s2.printStack( cout );
	cout << endl;

	cout << "print s1" << endl;
	s1.printStack( cout );
	cout << endl;

}
