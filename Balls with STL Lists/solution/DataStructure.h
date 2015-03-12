//Nehemiah Chong Song Yan
//A0111966A
//Lab Group 5
//Lab 05 - Linked Lists

#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

class DataStructure {
private:
    list<int> _balls;
    int _size;
    int _locate (int target);
    
public:
    DataStructure(int n);
    string toString();
    void A(int x, int y);
    void B(int x, int y);
    void R(int x);

}; 


#endif
