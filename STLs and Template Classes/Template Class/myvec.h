//Nehemiah Chong Song Yan
//A0111966A
//Tutorial Group 1
//Tutorial 07 Q3


#ifndef MYVEC_H
#define MYVEC_H

#include<iostream>
#include <sstream> //added for toString
#include <string>

using namespace std;

template <typename T>
class myvec {
private:
    T* _vec;    //or T _vec[1]?     //use a pointer to T so that dynamic arrays can be pointed to when updating capacity.
    int _size;  //variable holds the total number of entries in the array, not the capacity.
    int _capacity;  //variable holds the total capacity of the array, not the total number of entries.
    
public:
    myvec()     // Default Constructor which creates an internal array of capacity 1.
    {
        _vec = new T[1];	//default constructor points _vec to a dynamicallly created array of capacity 1.
        _size = 0;
        _capacity = 1;
    }
    
    ~myvec()   // Destructor.
    {
    }
    
    bool isEmpty() // Return true if the vector is empty.
    {
        return (_size == 0);
    }
    
    int size()     // Return the number of entries occupied.
    {
        return _size;
    }
    
    T at(int index)     // Return the value found at index (0-based).
    {
        return _vec[index];
    }
    
    void push_back(T value)     // Enter the value into the last entry.
    {
        if(_size == _capacity) {	//check if the array is full.
            _capacity *= 2;		//double the capacity.
            T* tempVec = new T[_capacity];	//create a new pointer tempVec that points to a dynamic array of the doubled capacity.
            
            for (int i=0; i<_size; i++) {	//copy the elements from the existing array into tempVec.
                tempVec[i] = _vec[i];
            }
            
            tempVec[_size] = value;		//add the new value to the back of the new array.
            _size++;
            
            //LOOK HERE!! changed the replacement code for private array pointer
            delete[] _vec;
            _vec = tempVec;
	        //debugged. to ask why the three lines of code below do not work only for capacity=1 -> 2.

            /*
			_vec = tempVec;
            delete [] tempVec;
            tempVec = NULL;
            */
        }
        else
        {
            _vec[_size] = value;		//if array is not full, just add to the back and update size.
            _size++;
        }
        
    }
    
    bool pop_back()     // Discard the last entry. Return true if the operation is successful.
    {
        
        if (_size == 0)		//cannot pop if array is empty.
            return false;
        else
        {
            _size--;		//update size.
            
            if (_size < (_capacity/4)) {	//check if size is less than a quarter of capacity. if true, halve the capacity.
                _capacity /= 2;		//half the capacity.
                T* tempVec = new T[_capacity];	//create a new pointer tempVec that points to a dynamic array of the halved capacity.
                
                for(int i=0; i<_size; i++){		//copy the existing elements into the new array. last element is popped since it is not copied over.
                    tempVec[i] = _vec[i];
                }
                
            	//LOOK HERE!! change the replacement code for private array pointer                
                delete[] _vec;
                _vec = tempVec;
                //debugged. to ask why the three lines of code below do not work only for capacity=1 -> 2.
                
				/*
				_vec = tempVec;
                delete [] tempVec;
                tempVec = NULL;
                */
            }
            
            return true;
        }

    }
    
    int capacity()      // Return the capacity of the array.
    {
        return _capacity;
    }
    /*
    void printVec()     // Print the array. Not sure why the usual toString function with ostringstream does not work, to ask.
    {
        cout << "myvec contains: ";
        for (int i=0; i<_size; i++) {
            cout << _vec[i] << " ";
        }
        cout << endl;
        
    }
    */

    string toString()	// Print the array.
    {
    	ostringstream oss;
    	for(int i=0; i<_size;i++) {
    		oss << _vec[i] << " ";
    	}
    	oss << endl;
    	return oss.str();
    }
};
#endif
