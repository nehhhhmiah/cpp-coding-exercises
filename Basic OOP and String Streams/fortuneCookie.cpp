//Name: Nehemiah Chong Song Yan
//Matric No.: A0111966A
//Tutorial 2 Q4
//Tutorial Group 1

#include <iostream>
#include <string>

using namespace std;

string overlap (string in1, string in2) {			//overlap is used to test whether the two strings provided overlap.
	int length1 = in1.length(), length2 = in2.length();
	string tempIn1, tempIn2 = in2;
	
	if (length2 > length1) {		//check if strings are of same length, if second is longer than the first then make the tempIn2 string the substring of in2 up to length1.
		tempIn2 = in2.substr(0, length1);
		length2 = length1;
	}
	
	while (length2 > 0) {			//while loop compares the two strings until tempIn2 is an empty string.
		tempIn1 = in1.substr(length1-length2, length2);		//tempIn1 is set to hold the substring to be compared. initally to the start of in1, but the while loop drops the first letter of the tempIn1 until the common string is found.
		
		if (tempIn1 == tempIn2) {		//compare tempIn1 defined above with tempIn2.
			tempIn1 = in1.substr(0, length1-length2);		//if there is a match, the string up to that index is taken and appended to in2 to get rid of the repeated substring.
			return tempIn1 + in2;
		}
		else {
			tempIn2 = tempIn2.substr(0,length2-1);			//if there is no match, the last letter of tempIn2 is dropped and the while loop repeats.
			length2--;
		}
	}
	
	return "";		//return an empty string if there is no match found.
}

string decideFortune (string res1, string res2, string in1, string in2) {		//decideFortune takes in the results of overlap and the initial strings and decides if the fortune can be told.
	if ((res1 == "") && (res2 == ""))		//if both results of overlap return an empty string, no overlap was found and so the fortune remains a mystery.
		return " remains a mystery.";
		
	if (res1 == in1)						//if the result from the first overlap test is the same as in1, then in1 is returned, although the fortune may be shorter than the actual one.
		return ": " + in1;
	else
		if (res2 == in2)					//if the result from the first overlap test is empty but the second overlap returns the same string as in2 & is not the same as in1, then return in2.
			return ": " + in2;
	
	if ((res1 != "") && (res1 != in1)) 		//if res1 is not empty & is not the same as in1, then return res1.
		return ": " + res1;
	if ((res2 != "") && (res2 != in2)) 		//if res2 is not empty & is not the same as in2, then return res2.
		return ": " + res2;
	
	return " remains a mystery.";			//catch all
}


int main() {
	string in1, in2, res1, res2;
	
	/* to take input from user, uncomment this section and comment out the rest of the code in main.
	cout << "Enter 1st piece: ";
	getline (cin, in1);
	cout << "Enter 2nd piece: ";
	getline (cin, in2);

	res1 = overlap(in1, in2);
	res2 = overlap(in2, in1);
	
	cout << "The fortune" << decideFortune(res1, res2, in1, in2) << endl;
	*/
	
	//case 1:
	cout << "1st piece: You will never" << endl;
	in1 = "You will never";
	cout << "2nd piece: never say die." << endl;
	in2 = "never say die.";

	res1 = overlap(in1, in2);
	res2 = overlap(in2, in1);
	
	cout << "The fortune" << decideFortune(res1, res2, in1, in2) << endl;
	cout << endl;
	
	//case 2:
	cout << "1st piece: You" << endl;
	in1 = "You";
	cout << "2nd piece: die." << endl;
	in2 = "die.";

	res1 = overlap(in1, in2);
	res2 = overlap(in2, in1);
	
	cout << "The fortune" << decideFortune(res1, res2, in1, in2) << endl;
	cout << endl;
	
	//case 3:
	cout << "1st piece: You will never never" << endl;
	in1 = "You will never never";
	cout << "2nd piece: never say die." << endl;
	in2 = "never say die.";

	res1 = overlap(in1, in2);
	res2 = overlap(in2, in1);
	
	cout << "The fortune" << decideFortune(res1, res2, in1, in2) << endl;
	cout << endl;
	
	//case 4:
	cout << "1st piece: er will coat every surface of the batmobile with silly putty." << endl;
	in1 = "er will coat every surface of the batmobile with silly putty.";
	cout << "2nd piece: On 6 September 2011, The Joker will coat eve" << endl;
	in2 = "On 6 September 2011, The Joker will coat eve";

	res1 = overlap(in1, in2);
	res2 = overlap(in2, in1);
	
	cout << "The fortune" << decideFortune(res1, res2, in1, in2) << endl;
	cout << endl;
	
	return 0;
}
