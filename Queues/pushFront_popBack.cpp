//Nehemiah Chong Song Yan
//A0111966A
//Tutorial Group 1
//Tutorial 8 Qn 3

#include<iostream>

using namespace std;

template<typename T>
void Queue<T>::push_front (const T& newltem) {		//push items to the front of the queue
	for(int i=_back; i>=_front; i--)	//for loop that traverses from back to front
		_items[i+1] = _items[i];	//shift all the items in the array back by one index to clear up first space
	_items[_front] = newItem;	//input new item at the front
	++_count;	//increase count
}


template <typename T>
void Queue<T>:: pop_back (T& queueBack){	//pop the item at the back of the queue
	queueBack = _items[_back];		//return the item at the end of the queue to the reference variable queueBack
	--_back;	//decrease index of _back by one to simulate pop.
}

