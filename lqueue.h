/*
* lqueue.h
* Modified : 25/08/2023
*
* This class represents the header for a templated Queue using a linked list as the underlying collection.
* This file should be used in conjunction with Assignment 2 for SENG1120.
*/

#ifndef SENG1120_LQUEUE_H
#define SENG1120_LQUEUE_H

#include <list>
#include "empty_collection_exception.h"

template <typename T>
class LQueue
{
public:
    /*
    * Precondition: None
    * Postcondition: A new LQueue is created, with all variables initialised.
    */
	LQueue();

    /*
    * Precondition: None
    * Postcondition: The LQueue is destroyed and all associated memory is freed.
    */
	~LQueue();

    /*
    * The supplied data is inserted at the rear of the queue.
    *
    * Precondition: The queue is initialised.
    * Postcondition: The data is inserted at the rear of the queue.
    */
	void enqueue(const T& data);

    /*
    * Removes and returns the front element from the queue.
    * If the queue is empty, an empty_collection_exception is thrown.
    *
    * Precondition: The queue is initialised and not empty.
    * Postcondition: The front element is removed and returned.
    */
	T dequeue();

    /*
    * Returns a reference to the front element on the queue.
    * If the queue is empty, an empty_collection_exception is thrown.
    *
    * Precondition: The queue is initialised and not empty.
    * Postcondition: The queue has not changed.
    */
	T& front();

    /*
    * Returns the number of items in the queue.
    *
    * Precondition: The queue is initialised.
    * Postcondition: The queue has not changed.
    */
	int size() const;

    /*
    * Returns true if the queue is empty, false otherwise.
    *
    * Precondition: The queue is initialised.
    * Postcondition: The queue has not changed.
    */
	bool empty() const;

private:
    std::list<T>* list;  // A pointer to the underlying list
    int count;           // The number of items in the queue
};

#include "lqueue.hpp"

#endif