//Name: Nehemiah Chong Song Yan
//Matric No.: A0111966A
//CS1020E Lab Group 5
//Lab 03

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

/**
 * isRunAroundNumbers: check if input is a runaroundnumber.
 */
bool isRunAroundNumbers(int num, int numOfDigits) {			//takes in input and the total number of digits, which was found using the isValid function.
	int numArray[numOfDigits];			//declare an array to hold individual digits.
	int counter=0, index=0;				//set counter and index for algorithm to zero.
	
	for(int i=(numOfDigits-1); i>=0; i--) {		//for loop to insert digits into the declared array, starting from the back so that array holds the number in its proper order i.e. 83261 comes out as {8, 3, 2, 6, 1} in the array.
		numArray[i] = num%10;
		num /= 10;
	}
	
	while(numArray[index] != 0) {		//execute a while loop to go through the number to test if it is runaround, and exit the while loop when a 0 is hit.
		int skip = numArray[index];		//declare the number of digits to skip as the digit in the current position of the array
		numArray[index] = 0;			//set the digit in that corresponding position to 0 so that the loop is exited if this index is hit again.
		index = (index+skip)%numOfDigits;	//set the index to the index of the next digit to go to by adding skip. %numOfDigits ensures that the index does not go out of the range of numOfDigits while returning the correct index.
		
		counter++;			//increase counter to count how many digits in the array have been checked.
	}
	
	if (counter==numOfDigits && index==0)	//return true if and only if all the digits have been checked and set to 0, and the last index is the first digit of the number. else return false.
		return true;
	else
		return false;

}

/**
 * isValid: check if number is valid - unique digits and no zeros. also return the number of digits using pointer.
 */
bool isValid (int num, int *numOfDigits) {		//boolean function takes in the number to be checked and a pointer from the main to store the total number of digits in the supplied number.
	int numArray[7] = {0};			//declare and initialize the array to hold the individual digits, declaring a max of 7 digits to hold since range is <10,000,000
	int i = 0, temp = num;			//use temp to hold the number to be processed.
	
	while(temp !=0) {			//read the supplied number into the corresponding position of the array, stop when the whole number is read in. the order of the number in the array is inconsequential since isValid checks only for zeros and unique digits.
		numArray[i] = temp%10;
		temp /= 10;
		i++;					//increase i so that the next digit goes into the next array position in the next loop.
	}
	
	*numOfDigits = i;			//dereference the pointer and set it to the total number of digits. numOfDigits will be used in isRunAroundNumber.
	
	for(int j=0; j<i; j++)		//for loop to check for zeros, return false if found.
		if(numArray[j] == 0)
			return false;
	
	if(num > 9) {			//nested for loop to check for repeated digits. only check if supplied number is more than 9, since anything 0<n<10 is a single number. return false if found.
		for(int j=0; j<(i-1); j++)
			for(int k=j+1; k<i; k++)
				if(numArray[j] == numArray[k])
					return false;
	}

	return true;		//return true both loops are cleared without returning false. number is valid.
}

/**
 * solve: return a runaroundnumber greater than input.
 */
int solve(int num) {
	bool check = false;
	int numOfDigits;
	
	while(!check) {			//use a while loop to check if the number supplied is valid, go to the next number if invalid. keep going until the next runaround number is found.
		if(isValid(num, (&numOfDigits)))
			check = isRunAroundNumbers(num, numOfDigits);		//run isRunAroundNumber to check number.
		num++;		//check next number
	}
	
	if(num < 10000000)
		return (num-1);		//return the number found and if in range.
	else {
		return -1;
	}
	
}

int main() {
	int num;		//variable to hold supplied number.
	
//	cout << "Enter a number: ";		//read input from user into variable.
	cin >> num;			//read number into variable.

	if (num > 9999999)	{	//check if input is within range.
		cout << "Input is out of range. Please enter a number below 10,000,000." << endl;
        return 0;
    }
    
	if (num > 9682415)		//check if next run around number is within range.
		cout << "Next Run Around Number is out of range." << endl;
	else
		cout << "Next Run Around Number is " << solve(num+1) << endl;		//print the next runAroundNumber, starting from num+1 so that num is not tested again.

	return 0;
}
