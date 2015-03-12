#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;       //enter n.
    
    while (((n%2)==0) || (n<1 || n>19)) {           //check that n is odd and between the given range, enter a loop until n is acceptable.
        if (n<1 || n>19)
            cout << "Please enter a number N such that 1 <= N <= 19." << endl;
    
        if ((n%2)==0)
            cout << "Please enter an odd number N." << endl;
        
        cin >> n;
    }
    
    int matrix[n][n];       //create 2D matrix of n x n to represent square.
    
    int i=0, j=n/2;         //starting cell is the middle cell of the top row.
	
	for(int counter=1; counter <= (n*n); counter++) {       //for loop to fill in the magic square.
		matrix[i][j] = counter;                             //assign counter the the current position [i][j].
		i--;                                                //move up one row.
		j++;                                                //move down one column.
		
		if (counter%n==0) {                                 //check to see if counter is a multiple of n, since next position is filled only if the counter is a multiple of n. if it is, move down two rows and left one column to simulate dropping to the cell directly below the previous cell
			i+=2;
			j--;
		}
	 	else {
			if (i<0)                                        //if the counter falls off from the top row, return to the bottom row.
                i += n;
            else if (j==n)                                  //if the counter falls off from the rightmost column, return to the leftmost column.
                j -= n;
		}
	}
    
    for (int i=0; i<n; i++) {                               //nested for loop to print the square.
		for (int j=0; j<n; j++) {
            if (j!=(n-1))                                   //if statement to set width to 4 and left justify the lines if they are not in the last column. if in the last column then just left justify so that there is no whitespace after.
                cout << setw(4) << left << matrix[i][j];
            else
                cout << left << matrix[i][j];
        }
		cout << endl;
	}
    
    return 0;
}

