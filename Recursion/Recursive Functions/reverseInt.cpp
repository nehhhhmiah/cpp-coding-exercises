//Nehemiah Chong Song Yan
//A0111966A
//Tutorial Group 1
//Tutorial 9 Q3

#include <iostream>

using namespace std;

int reverse (int n, int i = 0) {
	if (n == 0) {		//base case when n=0.
		return i/10;	//divide i by 10 since it was multiplied by 10 before returning.
	}
		
	else {
		i = (i + (n%10)) * 10;
		n /= 10;
		return reverse (n, i);
	}
		
}

int main () {
	int n;
	/* uncomment to take in user input.
	cin >> n;
	*/
	
	//test case 1
	n = 123;
	cout << "test case 1: " << n << " is reversed to " << reverse (n) << endl;
	
	//test case 2
	n = 2414913;
	cout << "test case 2: " << n << " is reversed to " << reverse (n) << endl;
	
	return 0;
}
