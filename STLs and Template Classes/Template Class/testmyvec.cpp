//Nehemiah Chong Song Yan
//A0111966A
//Tutorial Group 1
//Tutorial 07 Q3


#include "myvec.h"
#include <iostream>

using namespace std;

int main() {
    myvec<int> testMyVec;
    
    cout << "Test the constructor, isEmpty(), size() and capacity():" << endl;
    if (testMyVec.isEmpty())
        cout << "Size: " << testMyVec.size() << "\t\tCapacity: " << testMyVec.capacity() << endl; 	//should print, since the array is empty.
    
	cout << endl;
/*
for debugging purposes. problem only occurs when pushing back from capacity 1 to 2. after that no problem.
	testMyVec.push_back(1);
	testMyVec.push_back(2);
	
	cout << "LOOK HERE: " << testMyVec.at(0) << endl;
	cout << "LOOK HERE: " << endl;
	testMyVec.printVec();
	cout << endl;
end debugging section
*/

	for (int i=0; i<12; i++)		//push values from 0-11 into the array using push_back.
        testMyVec.push_back(i);
    
    cout << "Test push_back(int) and toString(), and check if size() and capacity() have been updated:" << endl;
    cout << testMyVec.toString(); 	//prints out the array using toString.
    cout << "Size: " << testMyVec.size() << "\tCapacity: " << testMyVec.capacity() << endl;		//checks if the size and capacity has updated. show extending.
	cout << endl;
	
/*
debugging - toString does not work if previous push_back method is used.   
    cout << "Test toString() function: Array contains: " << testMyVec.toString() << endl;
end debugging section
*/
	
    cout << "Test at() function: Element at index 5 is = " << testMyVec.at(5) << endl;
	cout << endl;

    cout << "Test pop_back(int), and check if size() and capacity() have been updated:" << endl;
    for (int i=0; i<11; i++)
        if(testMyVec.pop_back())
            cout << testMyVec.toString();
      
    cout << "Size: " << testMyVec.size() << "\t\tCapacity: " << testMyVec.capacity() << endl;
    
    
    return 0;
}
