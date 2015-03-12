//Nehemiah Chong Song Yan
//A0111966A
//Tutorial Group 1
//Tutorial 07 Q1

#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int** p = new int*[n];
	for (int i=0; i<n; i++)
		p[i] = new int[n];

	int val = 0;
	
	//row major placing
	for (int i=0;i<n;i++) {
		for (int j=0; j<n; j++) {
			p[i][j] = val;
			val++;
		}
	}

	//printing from bottom up
	for (int i=(n-1); i>=0; i--) {
		for (int j=0; j<n; j++) {
			cout << p[i][j] << " ";
		}
		cout << endl;
	}

	for (int i=0; i<n; i++) {
		delete [] p[i];
		p[i] = NULL;
	}
		
	return 0;
}
