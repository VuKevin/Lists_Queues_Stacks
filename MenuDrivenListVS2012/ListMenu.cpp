// Menu.cpp : Defines the entry point for the console application.
// Programmer Name: Kevin Vu
// 
// Date: 7/23/2015
// Purpose: Compare the implementation of Lists, Queues, and Stacks

// ******** NOTE: Include "Source.cpp" and disinclude "ListMenu.cpp" if you want to try the other test driver **************** // 

#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListIterator.h"
#include "List.cpp"
#include "ListNode.cpp"
#include "ListIterator.cpp"

using namespace std;
using namespace Lists;

enum CHOICE {MAKEEMPTY, REMOVE, ISEMPTY, FINDPREVIOUS, INSERT, QUIT, PRINT, APPEND, INSERTEND, SORTUP, DECR};

CHOICE menu();
void printList( const List<int>& l );

int main(int argc, char* argv[])
{
	int value;
	List<int> list;
	ListIterator<int> iter;

	CHOICE choice;
	do {
		choice = menu();
		switch( choice ) {
		case MAKEEMPTY:
			list.makeEmpty();
			break;
		case ISEMPTY:
			if (list.isEmpty()) {
				cout << "list is empty" << endl;
			}
			else {
				cout << "list is not empty" << endl;
			}
			break;
		case REMOVE:
			cout << "Please provide int to remove: ";
			cin  >> value; 
			list.remove( value );
			break;
		case INSERT:
			cout << "Please provide int to insert: ";
			cin  >> value; 
			list.insert( value );
			break;
		case FINDPREVIOUS:
			cout << "Please provide int to find: ";
			cin  >> value; 
			iter = list.findPrevious( value );
			if (iter.isValid()) {
				cout << "previous element = " << iter.retrieve() << endl;
			}
			else {
				cout << "data element was not found!" << endl;
			}
			break;
		case PRINT:
			printList( list );
			break;
		case APPEND: // Added
			list.insert(list);
			break;
		case INSERTEND: // Added
			cout << "Please provide int to insert to end: ";
			cin >> value;
			list.insertEnd(value);
			break;
		case SORTUP: // Added
			cout << "Ordering them by ascending order:" << endl;
			list.sort();
			break;
		case DECR:
			cout << "Ordering them by decreasing order:" << endl;
			list.sortD();
			break;
	}	

	} while (choice != QUIT);

	return( 0 );
}

int sample() {
	cout << "Forming Lists" << endl;
	int one = 1, two = 2;
	List<int> l1 = List<int>();
	List<int> l2 = List<int>();

	l1.insert( one );
	l1.insert( two );

	cout << "print l1" << endl;
	printList( l1 );

	cout << "l2 = l1" << endl;
	l2 = l1;

	cout << "print l2" << endl;
	printList( l2 );	

	cout << "l1.remove(one)" << endl;
	l1.remove( one );

	cout << "print l1" << endl;
	printList( l1 );

	cout << "print l2" << endl;
	printList( l2 );
	cout << "findPrevious 1 in l2" << endl;
	ListIterator<int> iter = l2.findPrevious( one );
	if (iter.isValid()) {
		cout << "--iter valid" << endl;
		cout << iter.retrieve() << endl;
	}
	else {
		cout << "--iter not valid" << endl;
	}

	cout << "findPrevious 2 in l2" << endl;
	iter = l2.findPrevious( two );
	if (iter.isValid()) {
		cout << "--iter valid" << endl;
		cout << iter.retrieve() << endl;
	}
	else {
		cout << "--iter not valid" << endl;
	}

	cout << "findPrevious 1 in l1" << endl;
	iter = l1.findPrevious( one );
	if (iter.isValid()) {
		cout << "--iter valid" << endl;
		cout << iter.retrieve() << endl;
	}
	else {
		cout << "--iter not valid" << endl;
	}

	cout << "findPrevious 2 in l1" << endl;
	iter = l1.findPrevious( two );
	if (iter.isValid()) {
		cout << "--iter valid" << endl;
		cout << iter.retrieve() << endl;
	}
	else {
		cout << "--iter not valid" << endl;
	}

	cout << "print l1" << endl;
	printList( l1 );	

		// you can remove whatever you want, whether it exists or not
	cout << "l1.remove(one)" << endl;
	l1.remove( one );

	cout << "print l1" << endl;
	printList( l1 );	

	return( 0 );
}

void printList( const List<int>& l ) 
{
	if (l.isEmpty())
		cout << "Empty list" << endl;
	else {
		ListIterator<int> iter = l.first();
		while (iter.isValid()) {
			cout << iter.retrieve() << " -> ";
			iter.advance();
		}
		cout << "NULL";
		cout << endl;
	}
}

CHOICE menu() {
	char choice;
	CHOICE result;
	cout << "(M)kEmp I(s)Emp (R)emo (I)ns (F)indPrev Srt(U)p (A)ppnd Ins(E)nd (P)rnt (Q)uit: " << endl;
	cin  >> choice;
	switch( choice ) 
	{
		case 'M':
		case 'm':
			result = MAKEEMPTY;
			break;
		case 'S':
		case 's':
			result = ISEMPTY;
			break;
		case 'R':
		case 'r':
			result = REMOVE;
			break;
		case 'I':
		case 'i':
			result = INSERT;
			break;
		case 'F':
		case 'f':
			result = FINDPREVIOUS;
			break;
		case 'Q':
		case 'q':
			result = QUIT;
			break;
		case 'P':
		case 'p':
			result = PRINT;
			break;
		case 'a':
		case 'A':
			result = APPEND;
			break;
		case 'e':
		case 'E':
			result = INSERTEND;
			break;
		case 'U':
		case 'u':
			result = SORTUP;
			break;
		case 'd':
		case 'D':
			result = DECR;
			break;
}

	return( result );
}
