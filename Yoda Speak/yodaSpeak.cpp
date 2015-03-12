//CS1020E
//Tutorial 1 Q2
//A0111966A


#include <iostream>
#include <string>
#include <sstream>
#include <string>
using namespace std;

string YodaSpeak (string input);

int main () {
	string input;
	getline(cin, input);
	cout << YodaSpeak(input) << endl;
	
	return 0;
}

string YodaSpeak (string input) {
	string verb, subject, word, output;
	
	istringstream in(input);
	ostringstream out;
	
	in >> subject >> verb;						//since first two words are assumed to be "subject" followed by "verb", read and store in respective strings.
	
	subject[0] = tolower(subject[0]);			//change the first letter of the subject to lowercase.
	input.clear();								//clears the input string to be used to store the rest of the sentence.
	while (in >> word)							//while loop pipes out each word since istringstream ignores whitespace
		  input += word + " ";					//adds a space after each word for proper spacing. Note that there will be a space after the last word, but get around that by searching first of ".,?!" instead of ".,?! ".
	
	input[0] = toupper(input[0]);				//change the first letter of the remaining string to uppercase.
	
	size_t end = input.find_first_of(".,!?");	//mark the end of the line as the position of the punctuation.
	if (end != string::npos)					//check if end found a match with ".,!?".
	   input = input.substr(0, end);			//drop the punctuation.
	
	out << "Yoda Speak: " << input << ", " << subject << " " << verb << endl; //move the input in front of the subject and verb.
	output = out.str();
	return output;
}

