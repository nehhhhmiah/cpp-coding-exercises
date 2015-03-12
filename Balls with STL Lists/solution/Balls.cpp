#include <iostream>
#include "DataStructure.h"

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	
	if (N > 1000 || N < 1 || M > 1000 || M < 1) {
			cout << "Error, please make sure N and M are within the range of 1 <= N, M <= 1000." << endl;
			return 0;
		}

	DataStructure ball(N);
	
	for(int i=0; !cin.eof() && i<M; i++) // loop for M times and not eof
	{
		char op;
		int x, y;
		cin >> op;
		if(op == 'R')
			cin >> x; // R operation only takes in 1 parameter
		else
			cin >> x >> y; // A and B operations take in 2 parameters
		
		switch(op)
		{
			case 'A':
				ball.A(x,y);
				break;
			
			case 'B':
				ball.B(x,y);
				break;
			
			case 'R':
				ball.R(x);
				break;
				
			default:
				break;
		}
	}		
	cout<< ball.DataStructure::toString();
	

    return 0;
}
