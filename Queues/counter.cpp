//Nehemiah Chong Song Yan
//A0111966A
//Tutorial Group 1
//Tutorial 8 Qn 6


#include <iostream>
#include <string>
#include <sstream>
#include <queue>


using namespace std;

unsigned int counter() {
// Precondition: None
// Postcondition: A line of input has been read from cin, up to but
// excluding the newline character. White spaces are ignored.
// The return value of the function is the number of times that the Last // character of the line appeared somewhere in the line.
// For example, when the input is “ABBX DXDZX”, then
// the value returned is 3 since there are 3 X's in the input line.

	queue<char> charQueue;
	string input, holder;
	getline(cin, input);
	
	istringstream in(input);
	
	input.clear();
	while (in >> holder)
		  input += holder;						//gets rid of whitespace if any

	int strLength = input.length();
	
	for (int i=0; i<strLength; i++)		//feeds the input without whitespace into the queue
		charQueue.push(input[i]);
	

	char lastChar = charQueue.back();
	unsigned int count = 0;

	for (int i=0; i<strLength; i++){
		if (charQueue.front() == lastChar)
			count++;
		charQueue.pop();
	}

	return count;
}

int main() {
	cout << counter() << endl;
	return 0;
}


