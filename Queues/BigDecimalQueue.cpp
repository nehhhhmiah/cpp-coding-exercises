//Nehemiah Chong Song Yan
//A0111966A
//Tutorial Group 1
//Tutorial 8 Qn 4

#include<iostream>
#include<sstream>
#include<string>
#include<queue>
#include<cstdlib>
#include<iomanip>

using namespace std;

void readBDQ (queue<int>& BDQ, string input) {
	queue<string> stringBDQ;
	string temp;
	int count=0, holder;
//	getline(cin, input); //for user input.
	istringstream in(input);
	
	while (in >> temp) {
		stringBDQ.push(temp);
		count++;
	}
	
	for (int i=0; i<count; i++) {
		holder = atoi((stringBDQ.front()).c_str());
		BDQ.push(holder);
		stringBDQ.pop();
	}	
}

queue<int> multiplyBDQ (queue<int>& BDQ, int n) {
	queue<int> newBDQ;
	int oldElement, tempElement, newElement, carry=0;
	int size = BDQ.size();
	
	for (int i=0; i<size; i++) {
		oldElement = BDQ.front();
		tempElement = oldElement*n + carry;
		if (tempElement>10000) {
			newElement = tempElement%10000;
			carry = tempElement/10000;
		}
		else {
			newElement = tempElement;
			carry = 0;
		}
		newBDQ.push(newElement);
		BDQ.pop();
	}
	if (carry!=0)
		newBDQ.push(carry);
	
	return newBDQ;
}

void printBDQ(queue<int> BDQ) {
	int size = BDQ.size();
	
	for (int i=0; i<size; i++) {
		cout << setw(4) << setfill('0') << BDQ.front() << " ";
		BDQ.pop();
	}
	cout << endl << endl;
}


int main() {
	queue<int> BDQ;
	queue<int> newBDQ;

	//test case 1
	string input = "5040 0080 5121";
	int n = 8;	
	readBDQ(BDQ, input);
	newBDQ = multiplyBDQ(BDQ, n);
	cout << "BDQ to be multiplied: " << input << endl;
	cout << "Multiply by: " << n << endl;
	printBDQ(newBDQ);
	
	//test case 2
	input = "4567 0123 1125 0024 4486";
	n = 13;
	readBDQ(BDQ, input);
	newBDQ = multiplyBDQ(BDQ, n);
	cout << "BDQ to be multiplied: " << input << endl;
	cout << "Multiply by: " << n << endl;
	printBDQ(newBDQ);
	
	
	return 0;
}
