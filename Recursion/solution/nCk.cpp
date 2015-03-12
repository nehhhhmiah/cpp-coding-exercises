//Nehemiah Chong Song Yan
//A0111966A
//Lab Group 5
//Lab 10

#include <iostream>
#include <string>

using namespace std;

void nCk (int k, string input, string output = "") {    //default value of output is an empty string.
    if (k == output.size()) {       //base case 1: if the length of the output string == the indicated length k.
        cout << output << endl;
        return;
    }
    
    if (k > input.size() + output.size())   //base case 2: if the total length of input and output strings is less than k.
        return;
    
    nCk(k, input.substr(1), output + input.substr(0,1));    //call the function nCk again but this time dropping the first character of the input and appending it to the input string.
    nCk(k, input.substr(1), output);    //call the function, only dropping the first character of the input. this is so that the further combinations not starting with the first character will be churned out.
}

int main() {
	int k;
    string input;
    cin >> k >> input;
	if (k<1 || k>16) {      //check range of k.
		cout << "Please enter a number within the range of 1 <= n <= 16." << endl;
		return 0;
	}

    nCk(k, input);
	
	return 0;
}
