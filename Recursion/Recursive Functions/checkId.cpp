//Nehemiah Chong Song Yan
//A0111966A
//Tutorial Group 1
//Tutorial 9 Q2

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/*
1st char can be = {'a' to 'z' || 'A' to 'Z' || '_'}.
the rest can be = {'a' to 'z' || 'A' to 'Z' || '_' || 0 to 9}
*/
bool recIsId (string Id, string::iterator iter) {
	if (*iter == *Id.end())
		return true;
	
	if (*iter == *Id.begin())
		if (!((*iter >= 'a' && *iter <= 'z') || (*iter >= 'A' && *iter <= 'Z') || (*iter =='_')))
			return false;
	
	if (!((*iter >= 'a' && *iter <= 'z') || (*iter >= 'A' && *iter <= 'Z') || (*iter =='_') || (*iter >= '0' && *iter <= '9')))
		return false;
	
	return recIsId(Id, iter+1);
	
}

int main() {
	string Id;
	//test case 1
	Id = "_adsfa9";
	string::iterator iter = Id.begin();
	
	if (Id == "") {
		cout << "String is empty, it is not an Id." << endl;
		return false;
	}
	else
		cout << "String _adsfa9 is an Id: " << boolalpha << recIsId(Id,iter) << endl;
	
	//test case 2
	Id = "1afhak_2";
	iter = Id.begin();
	if (Id == "") {
		cout << "String is empty, it is not an Id." << endl;
		return false;
	}
	else
		cout << "String 1afhak_2 is an Id: " << boolalpha << recIsId(Id,iter) << endl;
	
	//test case 3
	Id = "";
	iter = Id.begin();
	if (Id == "") {
		cout << "String is empty, it is not an Id." << endl;
		return false;
	}
	else
		cout << "String "" is an Id: "<< boolalpha << recIsId(Id,iter) << endl;

	
	return 0;
}

