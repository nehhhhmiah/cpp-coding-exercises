//Nehemiah Chong Song Yan
//A0111966A
//Tutorial Group 1
//Tutorial 5 Qn 2

#include <iostream>
#include <sstream>
#include <string>
#include "RunAround.h"

using namespace std;

RunAroundChecker::RunAroundChecker( int number )
//Pre: Takes in a positive number
//Post: The number is split into digits and stored internally
//      In this case, as a linkedlist.
//      The check of RunAround property should also be performed.
{
    //Split the digits and store in a linked list
    _head = NULL;
    _size = 0;
    while (number != 0)
    {
          ListNode *newPtr = new ListNode;		//make a newPtr to store the individual digit
          newPtr->digit = number%10;	//extract individual digits from the back using %10
          newPtr->visited = false;	//initialize boolean value to be false 
          newPtr->next = _head;	//set the next ListNode pointer to point to the previous ListNode pointer.
          
          _head = newPtr;	//set the _head to point to newPtr, which holds the digit that was just stored.
          _size++;	//increase the size by one.
          number = number/10;	//drop the stored digit by /10.
    }
    
    
    //Uniqueness check
    ListNode *prevptr = _head;
    ListNode *curptr = prevptr->next;
    ListNode *temp;
    
    while (curptr!= NULL) {	//use curptr for the bigger loop, move both ptrs forward after each loop is completed.
    	temp = curptr;
    	while (temp != NULL) {	//use prevptr as the reference point, move temp forwards to check until temp hits the end.
    		if (temp->digit == prevptr->digit) {	//number is not runaround if digits are not unique.
				_runAround = false; 
            	return;
        	}
        	temp = temp->next;	//move temp forward, prevptr stays as the reference.
        }
    	curptr = curptr->next;	//move curptr to the next digit.
        prevptr = prevptr->next;	//move prevptr to the next digit.
    }
    
    //Run around check - number is run around if: 1) every digit is hit only once, and 2) the last digit that is hit is the first digit of the number.
    curptr = _head;		//reset curptr to _head.
    int counter = 0;	//set the counter for the number of loops to be 0.

    while (counter < _size) {	//continue the loop until each number has been hit, unless there is an early return within the loop.
        int jump = curptr->digit;	//set the number of digits to jump as the current digit.
        if (jump > _size)	//use this algorithm to minimize looping around the linked list.
        	jump %= _size;

        for(int i=0; i<jump; i++) {	//for loop to get to the next digit. if pointer hits the end of the list, jump back to the start of the list.
            curptr = curptr->next;
            if (curptr == NULL)
                curptr = _head;
        }
        
        if (curptr->visited == true) {	//for the first condition - if the digit has been visited, early return - the number is not runaround.
            _runAround = false;
            return;
        }
        else	//else set the digit as visited.
        	curptr->visited = true;
        
        counter++;
    }
    
    if (curptr != _head) {	//for the second condition - the curptr should end up at the head again after all the checks, if not, early return.
    	_runAround = false;
    	return;
    }
    	
    _runAround = true;
}


bool RunAroundChecker::isRunAround()
//Pre: None. (the constructor will split + check the number)
//Post: return whether this is a run around number
{
    return _runAround;
}

string RunAroundChecker::toString()
//Pre: None.
//Post: Return as string the digits stored and whether the digits are visited
{
    ListNode* cur;

    for (cur = _head; cur != NULL; cur = cur->next){
        cout << cur->digit << "[" << cur->visited << "] -> ";
    }
    cout << endl;
}
