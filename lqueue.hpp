/*
* lqueue.hpp
* Modified : 10/09/2023
*
* This class represents the implementation of the lqueue class using a linked list as the underlying collection.
* This file should be used in conjunction with Assignment 2 for SENG1120.
*/

//This method creates stack and its variables
template <typename T>
LQueue<T>::LQueue()
{
    //Creates queue from new list
    list = new std::list<T>();
    //Sets the count of queue elements to 0
    count = 0;
}

//This method deletes stack and frees all associated memory
template <typename T>
LQueue<T>::~LQueue()
{
    delete list;
}


//This method adds an item to the end of the queue
template <typename T>
void LQueue<T>::enqueue(const T& data)
{
    //Pushes data to back of the queue
    list->push_back(data);
    //Adds to total item count
    count++;
    }
    
    //This method removes and returns item at front of queue
template <typename T>
T LQueue<T>::dequeue()
{
    //Throws exception if stack is empty
    if(empty())
    {
        throw empty_collection_exception();
    }
    //Sets front item to variable to be returned later
    T& dequeueItem = list->front();
    //deletes front item and lowers item count
    list->pop_front();
    count--;
    //returns reference to the deleted item
    return dequeueItem;
}

//This method returns the top element from the queue
template <typename T>
T& LQueue<T>::front()
{
    //Throws exception if stack is empty
    if(empty())
    {
        throw empty_collection_exception();
    }
    //returns item at front of queue
    return list.front();
}

//This method returns the count variable which contains number of items in queue
template <typename T>
int LQueue<T>::size() const
{
    return count;
}

//This method returns true is the stack is empty and false has items in it
template <typename T>
bool LQueue<T>::empty() const
{
    //If count does return 0 return true
    //If count doesn't return 0 return false
    return count == 0;
}