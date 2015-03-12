//Nehemiah Chong Song Yan
//A0111966A
//Tutorial Group 1
//Tutorial 5 Qn 2

#ifndef RUNAROUND_H
#define RUNAROUND_H

#include <string>

using namespace std;

class RunAroundChecker
{

private:
    struct ListNode{
        int digit;      //store a single digit
        bool visited;   //have we visited this digit?
        ListNode *next;
    };
    //Note that we can also wraps {digit, visited} into a single
    //"item" package (e.g. through the use of pair clss), then the 
    // ListNode will have a consistent representation of {item, next}.

    ListNode* _head;
    int _size;
    bool _runAround;    //whether this is a run around number

public:
    RunAroundChecker( int number );
    //Pre: Takes in a positive number
    //Post: The number is split into digits and stored internally
    //      In this case, as a linkedlist.
    //      The check of RunAround property should also be performed.

    bool isRunAround();
    //Pre: None. (the constructor will split + check the number)
    //Post: return whether this is a run around number

    string toString();
    //Pre: None.
    //Post: Return as string the digits stored and the run around property.
};

#endif
