//Nehemiah Chong Song Yan
//A0111966A
//Lab Group 5
//Lab 07

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

bool isFormationValid (int n, string formationToCheck) {
	stack<int> junction;	//use a stack to mirror the junction, since the junction is a stack - first in last out.
	int outID;	//the ID of the soldier exiting the junction.
	istringstream iss(formationToCheck);	//wrap the formation to be checked by John in a istringstream so that it can be converted and pushed one by one into the outID for comparison with inID.
	iss >> outID;	//convert and push the soldier's ID into outID for comparison with inID.
	
	for (int inID=1; inID<=n; inID++) {		//use an index-1 for loop to simulate the original formation of soldiers coming from point A. Loop until all the soldiers entered have been checked.
		junction.push(inID);	//push the respective soldier into the junction.
		while(!junction.empty() && junction.top() == outID) {	//continue the while loop if the junction is not yet empty AND if the soldier at the top of the stack is the same as the current outID.
			junction.pop();		//if there is only one soldier in the junction, he will exit and go to point B. If more than one soldier, the soldier who entered last will exit the junction first.
			iss >> outID;	//convert and push the next soldier's ID into outID for the next comparison.
		}
	}
	
	return junction.empty(); // the junction will only be empty if the formation is allowed.
	
}

int main() {
	int n;
	string formationToCheck;
	
	cin >> n;
	getline(cin, formationToCheck);
	
	while (getline(cin, formationToCheck)) {
		if (isFormationValid(n, formationToCheck))
			cout << "YES";
		else
			cout << "NO";
		
		cout << endl;
	}
	
	return 0;
}
