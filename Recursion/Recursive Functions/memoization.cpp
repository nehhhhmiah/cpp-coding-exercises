//Nehemiah Chong Song Yan
//A0111966A
//Tutorial Group 1
//Tutorial 9 Q1

#include <iostream>
#define MAX 50

using namespace std;

int fib(int n, int* f) {
	if (n<=2)
		return 1;
	
	if (f[n] == 0) {		//memorization technique
		f[n] = fib(n-1, f) + fib(n-2, f);
	}
	else		//if number has been 'memorized', return straight away
		return f[n];
}

void fibInit(int* f) {		//helper function to init f[MAX]. is this needed though? seems to work fine even without this function.
	for(int i=0; i<MAX; i++)
		f[i] = 0;
}

int main() {
	int f[MAX] = {0};
	cout << "6th fib number is: " << fib(6,f) << endl;
	
	fibInit(f);
	cout << "20th fib number is: " << fib(20,f) << endl;
	
	fibInit(f);
	cout << "46th fib number is the max: " << fib(46,f) << endl;
	
	fibInit(f);
	cout << "47th fib number goes nuts: " << fib(47,f) << endl;
	
	cout << "Hence, maximum value of n for fib(n) to work is 46." << endl;
	
	return 0;
}
