//Name: Nehemiah Chong Song Yan
//Matric No.: A0111966A
//Tutorial Grp 1
//Tutorial 2 Q2,3


#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

class BankAcct 
{
private:
    int _acctNum;
    double _balance;

public:

    BankAcct( int aNum )
    //Constructor
    //Pre: None
    //Post: BankAcct object is created with account number initialized
    //      to aNum and balance to 0
    {  
        _acctNum = aNum;
        _balance = 0.0;
    }

    BankAcct( int aNum, double amt )
        : _acctNum( aNum ), _balance( amt )
    //Constructor
    //Pre: None
    //Post: BankAcct object is created with account number initialized
    //      to aNum and balance to amt
    {
        _acctNum = aNum;
        _balance = amt;
    }

    int withdraw( double amount )
    //Withdrawal Public Method
    //Pre: amount should be positive
    //Post: If amount is <= to the available balance, balance is
    //      decreased by amount, else balance remain unchanged
    //Return: 1 for successful withdrawal, 0 for failure
    {   
        if (_balance < amount)
            return 0; 
        _balance -= amount;
        return 1;            
    }

    void deposit( double amount )  
    //Deposit Public Method
    //Pre: amount should be positive
    //Post: If amount is is positive, balance is
    //      increased by amount, else balance remain unchanged
    {  
        if (amount > 0.0)
            _balance += amount;
    }

    int getAccountNumber( )  
    //Get Account Number Public Method
    //Pre:  None
    //Post: None (this method doesnt change the object)
    //Return: Account number is returned
    {  
        return _acctNum;
    }
    

    string toString()
    //Return Account Information as a string
    //Pre:  None
    //Post: None (this method doesnt change the object)
    //      Account number and balance are returned as string
    {  
        ostringstream oss;
        oss << "Acct No.: " << _acctNum << endl << "Balance: $" << fixed << setprecision(2) << _balance << endl; //set width of _balance so that 0.00 is printed instead of 0.
        return oss.str();
    }
    
};

/*************** End of BankAcct Class definition *********************/


int findBankAcct( BankAcct* baPtrArr[], int size, int targetAcctNum )
//Purpose: Look for bankAcct object with "targetAccNum" as account
//         number.
//Pre: baPtrArr[0...size-1] are valid BankAcct pointers
//Post: This function doesnt change the bank account object(s)
//Return:
//    - index (0..size-1) of the BankAcct object if found
//    - -1, otherwise
{
	for (int i=0; i < size; i++) {				//for loop checks the array of bank accounts to find a match with targetAcctNum and returns the index of that account if found.
		if (baPtrArr[i]->getAccountNumber() == targetAcctNum)
   			return i;
    }
        
    return -1;
}


void printAllBankAcct( BankAcct* baPtrArr[], int size )
//Purpose: Print out account information for BankAcct objects  
//Pre: baPtrArr[0...size-1] are valid BankAcct pointers
//Post: This function doesnt change the bank account object(s)
{
		for (int i=0; i<size; i++) {			//for loop to go through every bank account and use the public function toString() to print.
			cout << baPtrArr[i] -> toString();
			cout << endl;
		}
}

int main()
{
    BankAcct* baList[5];		//Suggested construct to hold 5 bank account objects eventually
    for (int i = 0; i <5; i++)
    	baList[i] = NULL;
    	
    int choice, totalAccounts = 0, acctNum, acctIndex;

    //Q3, Part C
    //Here's a simple code fragement to get you started
    do {
        //Print "Menu" and get user choice
        cout << "*************************\n";
        cout << "*     Bank of Heaven    *\n";
        cout << "*************************\n";
        cout << "Service available: \n";
        cout << "(1. New Acct, 2. Deposit,";
        cout << " 3. Withdrawal, 4. Print All, 5. exit)\n";
        cout << "Your choice: ";
        cin >> choice;

        //Perform appropriate service based on user's input into choice;
        switch( choice ){
            case 1:         //New Account
            	if (totalAccounts < 5) {			//if loop to check if total number of accounts have been created.
					cout << "Result: [" << (totalAccounts+1) << "/5] account created." <<endl;		//displays confirmation message.
					acctNum = 900001 + totalAccounts;
            		baList[totalAccounts] = new BankAcct(acctNum);		//use constructor to create bank account with acctNum and balance set to $0.00.
            		cout << baList[totalAccounts] -> toString();		//use public function to print out newly-created account information.
					totalAccounts++;		//increment the totalAccount count so that system can stop at 5.
            	}
            	
            	else
            		cout << "Result: Could not create account as you have created the maximum of 5 accounts." << endl; //error message for max accounts reached.
            	
                break;
            case 2:         //Deposit
            	double depAmt;					//take in the account number and deposit amount from the user.
            	cout << "Account Number: ";
            	cin >> acctNum;
            	cout << "Deposit Amount: ";
            	cin >> depAmt;
            	
            	acctIndex = findBankAcct(baList, totalAccounts, acctNum);		//look for the corresponding index of the given account in the array of accounts using the findBankAcct function. if not found, -1 is returned.
            	if (acctIndex >= 0) {			//if found, use public deposit function and print out confirmation message and updated account information.
            		baList[acctIndex] -> deposit(depAmt);
            		cout << "Result: Deposit complete." << endl;
            		cout << baList[acctIndex] -> toString();
            	}
            	else
            		cout << "Result: Bank Account not found." << endl;		//if -1 is returned, indicates that the input account number does not exist in the list of created accounts.
            	
                break;
            case 3:         //Withdrawal
            	double withdrawalAmt;		//take in the account number and withdrawal amount from the user.
            	cout << "Account Number: ";
            	cin >> acctNum;
            	cout << "Withdrawal Amount: ";
            	cin >> withdrawalAmt;
            	
            	acctIndex = findBankAcct(baList, totalAccounts, acctNum);		//look for the corresponding index of the given account in the array of accounts using the findBankAcct function. if not found, -1 is returned.
            	if (acctIndex >= 0) {			//if found, use public withdrawal function
            		if (baList[acctIndex] -> withdraw(withdrawalAmt)) {			//since return type of withdrawal is either 1 or 0, use it to check if withdrawal was successful or not.
    	        		cout << "Result: Withdrawal complete." << endl;			//if successful, print out confirmation message and updated account information.
        	    		cout << baList[acctIndex] -> toString();
        	    	}
        	    	else
        	    		cout << "Result: Withdrawal could not be performed. Please kindly proceed into the branch for assistance." << endl; //error message for if withdrawal amount exceeds balance.
            	}
            	else
            		cout << "Result: Bank Account not found." << endl;		//if -1 is returned, indicates that the input account number does not exist in the list of created accounts.
            
                break;
            case 4:         //Print All
            	printAllBankAcct(baList, totalAccounts);
                	
				break; 
            case 5:         //Exit
            	cout << "Result: Thank you for banking with us!" << endl;
                break; 
            default:
                cout << "Result: Invalid choice!\n";
        }
    } while ( choice != 5 );

    return 0;
}
