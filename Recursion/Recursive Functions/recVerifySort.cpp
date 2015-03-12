//Nehemiah Chong Song Yan
//A0111966A
//Tutorial Group 1
//Tutorial 9 Q4

#include <iostream>
#include <iomanip>

using namespace std;

//time complexity for this function is = O(1)
bool recVerify (int* arr, int size) {
	if (size == 0)
		return true;
	if (arr[size-1] < arr[size-2])
		return false;
	
	size--;
	return recVerify (arr, size);
}


int main () {
	
	//test case 1
	int arr1[5] = {1,2,3,4,5};
	cout << "Test case 1: Array {1,2,3,4,5} is sorted: " << boolalpha << recVerify (arr1, 5) << endl;
	
	//test case 2
	int arr2[5] = {4,2,1,3,5};
	cout << "Test case 2: Array {4,2,1,3,5} is sorted: " << boolalpha << recVerify (arr2, 5) << endl;
	
	return 0;
}
