//Nehemiah Chong Song Yan
//A0111966A
//Tutorial Group 1
//Tutorial 8 Qn 5


#include <iostream>
#include <queue>
#include <sstream>
//#include <algorithm>
#include <list>

using namespace std;

int checkSecondLargest(queue<int>& intQ) {
	queue<int> temp(intQ);
	list<int> holder;
	int size = temp.size();
	for (int i=0; i<size; i++) {
		holder.push_back(temp.front());
		temp.pop();
	}
	holder.list::sort();
	holder.list::pop_back();
	return holder.list::back();
}


string toString(queue<int>& intQ) {
	queue<int> temp(intQ);
	ostringstream oss;
	oss << "{ ";
	int size = temp.size();
	for (int i=0; i<size; i++) {
		oss << temp.front() << " ";
		temp.pop();
	}
	
	oss << "}" << endl;
	
	return oss.str();
}

int main () {
	queue<int> intQ;
	int n, input;
	
	/*	Uncomment to take in user input.
	cout << "Enter total number of integers in queue: ";
	cin >> n;
	
	for(int i=0;i<n;i++) {
		cin >> input;
		intQ.push(input);
	}
	*/
	
	//test case 1
	n = 5;
	for (input = n; input>0; input--)
		intQ.push(input);
		
	cout << "The second largest integer is: " << checkSecondLargest(intQ) << endl;
	cout << "The queue has not been destroyed: " << toString(intQ) << endl << endl;
	
	//test case 2 - add on to previous test case
	n=10;
	for (input = 5; input<n; input++)
		intQ.push(input);
	
	cout << "The second largest integer is: " << checkSecondLargest(intQ) << endl;
	cout << "The queue has not been destroyed: " << toString(intQ) << endl;
	
	return 0;
}
