//Nehemiah Chong Song Yan
//A0111966A
//Tutorial Group 1
//Tutorial 07 Q2

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

int main() {
	vector<int> testVector;
	  srand (time(0));

	for (int i=0; i<10; i++) {
		int n = rand();
		testVector.push_back(n);
	}
	
	for (vector<int>::iterator iter = testVector.begin(); iter != testVector.end(); iter++)
		cout << *iter << " ";

	cout << endl;

	int input;
	cin >> input;

	for (vector<int>::iterator iter = testVector.begin(); iter != testVector.end(); iter++) {
		if (*iter == input) {
			cout << "true" << endl;
			return 0;
		}
	}

	cout << "false"<< endl;

		
	return 0;
}
