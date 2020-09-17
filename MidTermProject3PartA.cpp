// Mickie Blair
// CIST 2361 - CRN 63227
// MidTerm Project - Project 3

#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
	double loanAmount;			//loan amount
	double interestRate;		//interest rate
	double monthlyPayment;		//monthly payment
	double monthlyInterestRate;	//monthly interest rate
	double monthlyInterestDue;	//interest amount for month
	double principalPayment;	//payment toward principal
	double loanBalance;			//loan amount minus the principal payment

	int numberOfPayments = 1;	//months needed to payment back the loan
	   	  
	//display introduction
	cout << "Loan Repayment Calculator\n" << endl;
	cout << "The program will ask the user to enter the\n";
	cout << "loan amount, interest rate, and monthly payment.\n";
	cout << "The program will calculate and display the number\n";
	cout << "of months it will take to repay the loan.\n" << endl;

	cout << setprecision(2) << fixed;

	//ask the user for loan amount
	cout << "Loan Amount: \t\t\t\t";
	cout << setw(3) << "$  ";
	cin >> loanAmount;

	//set the loan balance to the beginning loan amount
	loanBalance = loanAmount;

	//display blank line
	cout << endl;

	//ask the user for interest rate
	cout << "Interest Rate (7.2% - Enter 7.2): \t\t";
	cin >> interestRate;

	//display blank line
	cout << endl;

	//ask the user for monthly payment
	cout << "Monthly Payment Amount: \t\t";
	cout << setw(3) << "$   ";
	cin >> monthlyPayment;

	//display blank line
	cout << endl;

	//calculate monthly interest rate
	monthlyInterestRate = ((interestRate / 100) / 12);

	//use function to get monthly interest due
	monthlyInterestDue = loanBalance * monthlyInterestRate;

	//display message that the loan amount is too low
	while (monthlyPayment < monthlyInterestDue)
	{
		//display monthly interest due
		cout << "\nInterest Due: \t\t\t\t";
		cout << setw(3) << "$  ";
		cout << setw(8) << right << monthlyInterestDue << endl;

		//display blank line
		cout << endl;

		cout << "The monthly Payment is less than the interest due." << endl;
		cout << "The loan could not be repaid with a payment this amount.\n" << endl;
		cout << "Please enter a monthly payment greater than the interest due." << endl;

		//display blank line
		cout << endl;

		//ask the user for monthly payment
		cout << "Monthly Payment Amount: \t\t";
		cout << setw(3) << "$    ";
		cin >> monthlyPayment;

		//calculate monthly interest rate
		monthlyInterestRate = ((interestRate / 100) / 12);

		//use function to get monthly interest due
		monthlyInterestDue = loanBalance * monthlyInterestRate;

	}

	do
	{
		//calculate monthly interest due
		monthlyInterestDue = loanBalance * monthlyInterestRate;

		//calculate payment information
		principalPayment = monthlyPayment - monthlyInterestDue;

		//calculate the loan balance
		loanBalance -= principalPayment;

		if (loanBalance > 0)
		{
			//increment payment number
					numberOfPayments++;
		}

	}
	while (loanBalance > 0);

	//display blank line
	cout << endl;

	//number of months it will take to pay off the loan
	cout << "Months to Repay Loan: \t\t\t";
	cout << setw(8) << right << numberOfPayments << endl;

	return 0;
}

