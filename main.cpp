#include <iostream>
#include <cctype>
#include <iomanip>
#include <windows.h>

#include "Account.h"

using namespace std;

void displayMenu();
void makeDeposit(Account &);
void withdraw(Account&);

int main() {
	
	system("Color A");
	
	Account savings;
	char choice;

	cout << fixed << showpoint << setprecision(2);

	do
	{
		displayMenu();
		cin >> choice;
		while (toupper(choice) < 'A' || toupper(choice) > 'G')
		{
			cout << "Please make a choice in the range of A through G: ";
			cin >> choice;
		}

		switch (choice)
		{
		case 'a':
		case 'A':
			cout << "The current balance is $";
			cout << savings.getBalance() << endl;
			break;

		case 'b':
		case 'B':
			cout << "There have been ";
			cout << savings.getTransactions();
			cout << " transactions." << endl;
			break;

		case 'c':
		case 'C':
			cout << "Interest earned for this period: $";
			cout << savings.getInterest();
			break;

		case 'd':
		case 'D':
			makeDeposit(savings);
			break;

		case 'e':
		case 'E':
			withdraw(savings);
			break;

		case 'f':
		case 'F':
			savings.calcInterest();
			cout << "Interest added.";
			break;
		}

	} while (toupper(choice) != 'G');

	return 0;
}

void displayMenu() {

	cout << "       MENU         " << endl;
	cout << "--------------------" << endl;
	cout << "(A) Display current balance" << endl;
	cout << "(B) Display current number of transactions." << endl;
	cout << "(C) Display interest earned" << endl;
	cout << "(D) Make a deposit" << endl;
	cout << "(E) Make a withdrawal" << endl;
	cout << "(F) Add interest for this period" << endl;
	cout << "(G) Exit the program" << endl;
	cout << "Enter your choice" << endl;

}

void makeDeposit(Account& acnt) {
	
	double dollars;
	cout << "Enter the amount for the deposit" << endl;
	cin >> dollars;
	cin.ignore();
	acnt.makeDeposit(dollars);
}

void withdraw(Account& acnt) {
	double dollars;
	cout << "Enter the amount to withdraw." << endl;
	cin >> dollars;
	cin.ignore();

	if (!acnt.withdraw(dollars))
		cout << "ERROR. Withdrawal amount too large." << endl;

}
