// Mickie Blair
// CIST 2361 - CRN 63227
// MidTerm Project - Project 3

#include <iostream>
#include <iomanip>

using namespace std;

double calcMinPayment(double, double);

int main()
{
	double loanAmount;				//loan amount
	double interestRate;			//interest rate
	double minimumPayment;			//minumum montly payment
	double monthlyPayment;			//monthly payment
	double monthlyInterestRate;		//monthly interest rate
	double monthlyInterestDue;		//interest amount for month
	double principalPayment;		//payment toward principal
	double loanBalance;				//loan amount minus the principal payment
	int numberOfPayments = 1;		//months needed to payment back the loan
	double totalInterest = 0;		//total amount of loan over the entire period
	double lastPayment;				//loan amount plus interest amount due

	//display introduction
	cout << "Loan Repayment Calculator\n" << endl;
	cout << "The program will ask the user to enter the\n";
	cout << "loan amount, interest rate, and monthly payment.\n";
	cout << "The program will calculate and display the following:\n";
	cout << " - number of months it will take to repay the loan"<< endl;
	cout << " - amount of last payment" << endl;
	cout << " - total interest paid\n" << endl;

	cout << setprecision(2) << fixed;

	//ask the user for loan amount
	cout << "Loan Amount: \t\t\t\t";
	cout << setw(3) << "$  ";
	cin >> loanAmount;

	//display blank line
	cout << endl;

	//ask the user for interest rate
	cout << "Interest Rate (7.2% - Enter 7.2):   \t\t";
	cin >> interestRate;

	//display blank line
	cout << endl;

	//calculate monthly interest rate
	monthlyInterestRate = ((interestRate / 100) / 12);

	//call function to calculate minimum monthly Payment
	minimumPayment = calcMinPayment(loanAmount, monthlyInterestRate);

	//display the minimum payment
	cout << "Minimum Payment Amount: \t\t";
	cout << setw(3) << "$    ";
	cout << minimumPayment;

	//display blank line
	cout << endl;

	//ask the user for monthly payment
	cout << "\nMonthly Payment Amount: \t\t";
	cout << setw(3) << "$   ";
	cin >> monthlyPayment;

	//display blank line
	cout << endl;

	//display message that the payment amount is too low
	while (monthlyPayment < minimumPayment)
	{
		cout << "The monthly payment is less than the minimum payment." << endl;
		cout << "Please enter a monthly payment greater than or" << endl;
		cout << "equal to the minimum payment." << endl;

		//display blank line
		cout << endl;

		//ask the user for monthly payment
		cout << "Monthly Payment Amount: \t\t";
		cout << setw(3) << "$    ";
		cin >> monthlyPayment;
	}
	
	//set the loan balance to the beginning loan amount
	loanBalance = loanAmount;

	//use function to get monthly interest due
	monthlyInterestDue = loanBalance * monthlyInterestRate;
	
	while (loanBalance > monthlyPayment)
	{
		//calculate the monthly interest due
		monthlyInterestDue = loanBalance * monthlyInterestRate;

		//calculate payment information
		principalPayment = monthlyPayment - monthlyInterestDue;

		//calculate the loan balance
		loanBalance -= principalPayment;

		//calculate total interest
		totalInterest += monthlyInterestDue;

		//increment payment number
		numberOfPayments++;
	}

	//display blank line
	cout << endl;

	//display original loan amount
	cout << "Loan Amount: \t\t\t\t";
	cout << setw(2) << "$ ";
	cout << setw(8) << right << loanAmount << endl;

	//display blank line
	cout << endl;

	//calculate the monthly interest due on the remaining balance
	monthlyInterestDue = loanBalance * monthlyInterestRate;

	//adding last interest amount to total interest
	totalInterest += monthlyInterestDue;

	//set last payment eqauls to balance due
	lastPayment = loanBalance;

//display total interest paid
	cout << "Total Interest Paid: \t\t\t";
	cout << setw(2) << "$ ";
	cout << setw(8) << right << totalInterest << endl;

	//display blank line
	cout << endl;

	//display last Payment
	cout << "Final Payment: \t\t\t\t";
	cout << setw(2) << "$ ";
	cout << setw(8) << right << lastPayment << endl;

	//display blank line
	cout << endl;

	//number of months it will take to pay off the loan
	cout << "Months to Repay Loan: \t\t\t";
	cout << setw(8) << right << numberOfPayments << endl;

	return 0;
}

//function to calculate monthly minumum payment
double calcMinPayment(double loanAmount, double monthlyInterestRate)
{
	double minimum;		//minimum payment

	minimum = (loanAmount * monthlyInterestRate) + 0.01;

	return minimum;
}