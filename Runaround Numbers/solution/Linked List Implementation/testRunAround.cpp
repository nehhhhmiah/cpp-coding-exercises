//Nehemiah Chong Song Yan
//A0111966A
//Tutorial Group 1
//Tutorial 5 Qn 2

#include <iostream>
#include "RunAround.h"

using namespace std;

int main()
{
    int N;

    cout << "Enter N => ";
    cin >> N;

    RunAroundChecker check(N);

    //Just a "funner" way to print the result
    cout << "What is " << N << " doing?" << endl;
    if (check.isRunAround()){
        cout << "Ans: Run run run around!\n";
    } else {
        cout << "Ans: Stuck! Cannot run around!\n";
    }

    return 0;
}
