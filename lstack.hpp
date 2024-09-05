/*
* lstack.hpp
* Modified : 10/09/2023
*
* This class represents the implementation of the lstack class using a linked list as the underlying collection.
* This file should be used in conjunction with Assignment 2 for SENG1120.
*/

//This method creates stack and its variables
template <typename T>
LStack<T>::LStack()
{
	//Creates stack from new list
    list = new std::list<T>();
	//Sets the count of stack elements to 0
    count = 0;
}

//This method deletes stack and frees all associated memory
template <typename T>
LStack<T>::~LStack()
{
    delete list;
}

//Method inserts data into the stack at the front
template <typename T>
void LStack<T>::push(const T& data)
{
	//Pushes item to top of stack
    list->push_front(data);
	//adds 1 to total data count
    count++;
}

//This method removes the top element from the stack and then returns it
template <typename T>
T LStack<T>::pop()
{
	//Throws exception if stack is empty
    if(empty())
    {
        throw empty_collection_exception();
    }
	//Sets front item to variable to be returned later
    T& popItem = list->front();
	//deletes front item and lowers item count
    list->pop_front();
    count--;
	//returns the deleted item
    return popItem;
}

//This method returns the top element from the list
template <typename T>
T& LStack<T>::top()
{
	//Throws exception if stack is empty
    if(empty())
    {
        throw empty_collection_exception();
    }
	//returns the front item
    return list->front();
}

//This method returns the count variable which contains number of items in stack
template <typename T>
int LStack<T>::size() const
{
    return count;
}

//This method returns true is the stack is empty and false has items in it
template <typename T>
bool LStack<T>::empty() const
{
	//If count does return 0 return true
	//If count doesn't return 0 return false
    return count == 0;
}