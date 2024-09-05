/*
* lstack.h
* Modified : 25/08/2023
*
* This class represents the header for a templated Stack using a linked list as the underlying collection.
* This file should be used in conjunction with Assignment 2 for SENG1120.
*/

#ifndef SENG1120_LSTACK_H
#define SENG1120_LSTACK_H

#include <list>
#include "empty_collection_exception.h"

template <typename T>
class LStack
{
public:
	/*
	* Precondition: None
	* Postcondition: A new LStack is created, with all variables initialised.
	*/
	LStack();

	/*
	* Precondition: None
	* Postcondition: The LStack is destroyed and all associated memory is freed.
	*/
	~LStack();

	/*
	* The supplied data is inserted at the top of the stack.
	*
	* Precondition: The stack is initialised.
	* Postcondition: The data is inserted into the stack.
	*/
	void push(const T& data);

	/*
	* Removes and returns the top element from the stack.
	* If the stack is empty, an empty_collection_exception is thrown.
	*
	* Precondition: The stack is initialised and not empty.
	* Postcondition: The top element is removed and returned.
	*/
	T pop();

	/*
	* Returns a reference to the top element on the stack.
	* If the stack is empty, an empty_collection_exception is thrown.
	*
	* Precondition: The stack is initialised and not empty.
	* Postcondition: The stack has not changed.
	*/
	T& top();

	/*
	* Returns the number of items in the stack.
	*
	* Precondition: The stack is initialised.
	* Postcondition: The stack has not changed.
	*/
	int size() const;

	/*
	* Returns true if the stack is empty, false otherwise.
	*
	* Precondition: The stack is initialised.
	* Postcondition: The stack has not changed.
	*/
	bool empty() const;

private: 
	std::list<T>* list;  // A pointer to the underlying list
	int count;           // The number of items in the stack
};

#include "lstack.hpp"

#endif