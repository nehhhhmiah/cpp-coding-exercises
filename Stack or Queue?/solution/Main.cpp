//Nehemiah Chong Song Yan
//A0111966A
//Lab Group 5
//Lab 08

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

//to reverse a stack, simply push the values into a temporary queue. then, push the values of the queue back into the stack.
//FILO -> FIFO, thus the stack is reversed.
template<typename T>
void reverseStack(stack<T>& s) {
	queue<T> tempQueue;
	while (!s.empty()) {
		tempQueue.push(s.top());
		s.pop();
	}
	while (!tempQueue.empty()) {
		s.push(tempQueue.front());
		tempQueue.pop();
	}
}

//to reverse a queue, simply push the values into a temporary stack. then, push the values of the stack back into the queue.
//FIFO -> FILO, thus the queue is reversed.
template<typename T>
void reverseQueue(queue<T>& q) {
	stack<T> tempStack;
	while (!q.empty()) {
		tempStack.push(q.front());
		q.pop();
	}
	while (!tempStack.empty()) {
		q.push(tempStack.top());
		tempStack.pop();
	}
}


int main()
{
	stack<int> s;
	queue<int> q;
	int n, value;
	string operation;
	bool isStack, isQueue;

	
	while (cin >> n) {	//read in until end of file is reached.
		if (n<1 || n>20) {	//check for value of N to be within range of 1 <= n <= 20.
			cout << "Please enter a value between and inclusive of 1 and 20." << endl;
			return 0;
		}
		
		//"resetting" the stack and queue to be used.
		while (!s.empty())
			s.pop();
		while (!q.empty())
			q.pop();
		
		//"resetting" the boolean functions to check again.
		isStack = true;
		isQueue = true;
		
		//run a for loop for the next n lines according to user input.
		for(int i=0; i<n; i++) {
			cin >> operation;

			if (operation == "push") {	//if the operation to be carried out is push, simply call functions push from stack and queue STL.
				cin >> value;
				s.push(value);
				q.push(value);
			}
			
			else if (operation == "pop") {	//check the values of the number popped from the top of the stack and the front of the queue.
											//if they are not the same as the expected value, set isStack/isQueue to false respectively.
				cin >> value;
				
				if (s.top() != value)
					isStack = false;
				else
					s.pop();
					
				if (q.front() != value)
					isQueue = false;
				else
					q.pop();
			}
			
			else if (operation == "reverse") {	//use defined functions to reverse the stack and queue if the operation is reverse.
				reverseStack(s);
				reverseQueue(q);
			}
			
			else {		//catch all for unidentified operators.
				cout << "Operation not recognized." << endl;
				return 0;
			}
		}
		
		//print out the output based on tests in pop and continue taking in the next test case until end of file is reached.
		if (isStack && isQueue)
			cout << "stack or queue";
		else if (isStack && !isQueue)
			cout << "stack";
		else if (!isStack && isQueue)
			cout << "queue";
		else if (!isStack && !isQueue)
			cout << "impossible";
		
		cout << endl;
	}

	return 0;
}
