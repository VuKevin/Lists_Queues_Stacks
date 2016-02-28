// Menu.cpp : Defines the entry point for the console application.
// Programmer Name: Kevin Vu

// Date: 7/23/2015
// Purpose: Compare the implementation of Lists, Queues, and Stacks

#include <iostream>
#include "Queue.h"
#include "EmptyQueue.h"
#include "QueueNode.h"
#include "Queue.cpp"
#include "QueueNode.cpp"

using namespace std;
using namespace Queues;

enum CHOICE {MAKEEMPTY, ENQUEUE, ISEMPTY, DEQUEUE, GETFRONT, QUIT, PRINT, COUNT, ISDECREASING};

CHOICE menu();

int main(int argc, char* argv[]) 
{
	int value;
	Queue<int> q;

	CHOICE choice;
	do {
		choice = menu();
		switch( choice ) {
		case MAKEEMPTY:
			q.makeEmpty();
			break;
		case ISEMPTY:
			if (q.isEmpty()) {
				cout << "queue is empty" << endl;
			}
			else {
				cout << "queue is not empty" << endl;
			}
			break;
		case DEQUEUE:
			try {
				value = q.dequeue();
				cout << "Here's the value dequeued: ";
				cout << value << endl;
			} catch( EmptyQueue eq ) {
				cout << "You silly... don't try dequeueing an empty queue!" << endl;			
			}
			break;
		case GETFRONT:
			try {
				value = q.getFront();
				cout << "Here's the value returned from getFront: ";
				cout << value << endl;
			} catch( EmptyQueue eq ) {
				cout << "You silly... don't try gettingFront an empty queue!" << endl;
			}
			break;
		case ENQUEUE:
			cout << "Please provide int to enqueue: ";
			cin  >> value; 
			q.enqueue( value );
			break;
		case PRINT:
			q.printQueue( cout );
			cout << endl;
			break;
		case COUNT:
			cout << "Please provide the int to count for: ";
			cin >> value;
			cout << "There are " << q.count(value) << " instances of " << value << endl;
			break;
		case ISDECREASING:
			if (q.isEmpty())
			{
				cout << "The stack is empty";
				break;
			}
			if (q.isDecreasing())
				cout << "The stack is decreasing." << endl;
			else
				cout << "The stack is NOT decreasing." << endl;
			break;
	}	

	} while (choice != QUIT);

	return( 0 );
}

CHOICE menu() {
	char choice;
	CHOICE result;

	cout << "(M)kEmpt I(s)Empt (E)nq (D)eq (G)etFrnt (C)ount (I)sDecr (P)rnt (Q)uit: " << endl;
	cin  >> choice;
	switch( choice ) {
	case 'E':
	case 'e':
		result = ENQUEUE;
		break;
	case 'M':
	case 'm':
		result = MAKEEMPTY;
		break;
	case 'S':
	case 's':
		result = ISEMPTY;
		break;
	case 'D':
	case 'd':
		result = DEQUEUE;
		break;
	case 'G':
	case 'g':
		result = GETFRONT;
		break;
	case 'Q':
	case 'q':
		result = QUIT;
		break;
	case 'P':
	case 'p':
		result = PRINT;
		break;
	case 'c':
	case 'C':
		result = COUNT;
		break;
	case 'i':
	case 'I':
		result = ISDECREASING;
		break;
	}

	return( result );
}

void sample() {
	Queue<int> q1;
	Queue<int> q2;
	cout << "making q1" << endl;
	q1.enqueue( 1 );
	q1.enqueue( 2 );
	cout << "print q1" << endl;
	q1.printQueue( cout );
	cout << endl;

	cout << "q2 = q1" << endl;

	q2 = q1;
	cout << "print q2" << endl;
	q2.printQueue( cout );
	cout << endl;

	q1.dequeue();
	cout << "dequeue q1" << endl;

	cout << "print q2" << endl;
	q2.printQueue( cout );
	cout << endl;

	cout << "print q1" << endl;
	q1.printQueue( cout );
	cout << endl;

}
