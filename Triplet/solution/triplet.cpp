//Nehemiah Chong Song Yan
//A0111966A
//Lab Group 5
//Lab 09

#include <iostream>
#define MAXPOS 1000
#define MAXNEG -1000

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n<3 || n>50000) {
		cout << "Please enter a number within the range of 3 <= n <= 50,000." << endl;
		return 0;
	}
	
	int* arr;
	arr = new int[n];		//create a dynamic array to hold the integers.
	
	for (int i=0;i<n;i++)		//read in n integers.
		cin >> arr[i];
		
	int max1=MAXNEG, max2=MAXNEG, max3=MAXNEG;		//max1 will be the most positive number
	int min1=MAXPOS, min2=MAXPOS, min3=MAXPOS;		//min1 will be the most negative number.
	int numOfPos=0, numOfNeg=0;		//count the number of positive and negative numbers.
	int max, min;	//hold the max and min products.
	
	//find the three largest numbers and the three smallest numbers, whether positive or not. instead of sorting, which would require nested loops, feed in and compare numbers one by one.
	//N iterations, no nested loops, so it is still O(n).
	for (int i=0;i<n;i++) {
		//count the number of positive and negative numbers.
        if (arr[i]>0)
            numOfPos++;
        if (arr[i]<0)
            numOfNeg++;
        
        //find the three largest numbers.
        if (arr[i]>=max1) {
            max3=max2;
            max2=max1;
            max1=arr[i];
        }
        else if (arr[i]>=max2) {
            max3=max2;
            max2=arr[i];
        }
        else if (arr[i]>=max3) {
            max3=arr[i];
        }
        
        //find the three smallest numbers.
        if (arr[i]<=min1) {
            min3=min2;
            min2=min1;
            min1=arr[i];
        }
        else if (arr[i]<=min2) {
            min3=min2;
            min2=arr[i];
        }
        else if (arr[i]<=min3) {
            min3=arr[i];
        }
    }

	//max number= (-)(-)(+) smallest two negatives and largest positive, or (+)(+)(+) largest three positives. if input is all negative, then max number is the product of the three largest negatives (-)(-)(-).
	//min number = (+)(+)(-) largest two positives and smallest negative, or (-)(-)(-) smallest three negatives. if input is all positive, then min number is the product of the three smallest positives (+)(+)(+).
    if (numOfNeg==0 || numOfPos==0) {	//straightforward case if all positive or all negative.
        max=max1*max2*max3;
        min=min1*min2*min3;
    }
    else if (numOfPos==1) {		//if there is only one positive no, max is smallest two negatives and largest positive while min is the smallest three negative.
        max=max1*min1*min2;
        min=min1*min2*min3;
    }
    else if (numOfNeg==1) {		//if there is only one negative no, max is largest three positive and min is the negative and two largest positives.
    	max=max1*max2*max3;
        min=min1*max2*max1;
    }
    else {		//for any other case, need to compare which will give the greater product.
        if (max2*max3 > min1*min2)
            max=max1*max2*max3;
        else
            max=max1*min1*min2;
            
        if (max1*max2 > min2*min3)
            min=min1*max1*max2;
        else
            min=min1*min2*min3;
    }
    
    cout << min << " " << max << endl;
	
	//delete the dynamically allocated array and set to NULL so that no memory is leaked.
	delete[] arr;
	arr = NULL;
	
	return 0;
}
