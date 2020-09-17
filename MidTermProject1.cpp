// Mickie Blair
// CIST 2361 - CRN 63227
// MidTerm Project - Project 1

#include <iostream>
#include <iomanip>

using namespace std;

double calcIncome(double, double);
double calcNetIncome(double);
double calcExpenses(double);
void calcSavingsBond(double);

int main()
{
	double payRate;					//variable for pay rate
	double hoursWorked;				//variable for hours worked
	double income;					//variable for income
	double netIncome;				//variable for income after taxes
	double incomeAfterExpenses;		//variable for income after expenses

	//Display introduction
	cout << "The program will ask the user for the pay rate and hours worked. \n"
		<< "The computer will then output the following: \n\n"
		<< "- Income before and after taxes (14% of income)\n"
		<< "- Money spent on clothes and other accessories (10% of income)\n"
		<< "- Money spent on school supplies (1% of income)\n"
		<< "- Money spent to buy savings bonds (25% of remaining income)\n"
		<< "- Money parents spent on buying additional savings bonds ($0.50 for each $1.00)\n"
		<< endl;

	//Get pay rate and hours worked from user
	cout << "Enter the hourly pay rate and hours worked below.\n" << endl;
	
	cout << setw(22) << left << "Hourly Pay Rate:";
	cout << setw(1) << " $   ";
	cin >> payRate;

	cout << setw(22) << left << "Hours Worked:                 ";
	cin >> hoursWorked;

	//display blank line
	cout << endl;

	//set precision
	cout << setprecision(2) << fixed;

	//call function to get income
	income = calcIncome(payRate, hoursWorked);

	//call function to calculate and display taxes then return net income
	netIncome = calcNetIncome(income);

	//display blank line
	cout << endl;

	//call function to calculate and display taxes then return net income
	incomeAfterExpenses = calcExpenses(netIncome);

	//display blank line
	cout << endl;

	//call function to calculate savings bond contributions (user and parents)
	calcSavingsBond(incomeAfterExpenses);

	return 0;
}

//function to calculate, display and return income using pay rate and hours worked
double calcIncome(double pay, double hours)
{
	double income;				//variable for income

	//calculate income
	income = pay * hours;

	//display income
	cout << setw(22) << left << "Income:";
	cout << setw(2) << " $";
	cout << setw(8) << right << income << endl;

	//return income
	return income;
}

//function to calculate, display and return net income 
double calcNetIncome(double income)
{
	double netIncome;					//variable for net income
	double tax;							//variable for income
	const double TAX_PERCENT = .14;		//constant for tax percent

	//calculate income
	tax = income * TAX_PERCENT;

	//display taxes
	cout << setw(22) << left << "Taxes:";
	cout << setw(2) << " $";
	cout << setw(8) << right << tax << endl;


	//calculate net income
	netIncome = income - tax;

	//display net income
	cout << setw(22) << left << "Net Income:";
	cout << setw(2) << " $";
	cout << setw(8) << right << netIncome << endl;

	//return netIncome
	return netIncome;
}

//function to calculate and display amount spent on clothes/accessories and school supplies.  
//Return income after expenses
double calcExpenses(double netIncome)
{
	const double CLOTHES_PERCENT = .10;		//constant - percent spent on clothes
	const double SCHOOL_PERCENT = .01;		//constant - percent spent on school supplies

	double clothesAmt;					//amount spent on cloths
	double schoolAmt;					//amount spent on school supplies
	double incomeAfterExpenses;			//amount of remaining income
	

	//calculate amount spent on clothes and other expense
	clothesAmt = netIncome * CLOTHES_PERCENT;

	//display money spent on clothes
	cout << setw(22) << left << "Clothes/Accessories:";
	cout << setw(2) << " $";
	cout << setw(8) << right << clothesAmt << endl;

	//calculate amount spent on school supplies
	schoolAmt = netIncome * SCHOOL_PERCENT;

	//display money spent on school supplies
	cout << setw(22) << left << "School Supplies:";
	cout << setw(2) << " $";
	cout << setw(8) << right << schoolAmt << endl;

	//calculate the amount of remaining money
	incomeAfterExpenses = netIncome - clothesAmt - schoolAmt;

	//return netIncome
	return incomeAfterExpenses;
}


//function to calculate and display amount used on savings and parental savings contribution 
void calcSavingsBond(double incomeAfterExpenses)
{
	const double SAVINGS_PERCENT = .25;		//constant - percent used on savings bond
	const double PARENT_SAVINGS = .50;		//constant - parental contribution $0.50 per dollar

	double savingsAmt;					//amount used for savings bond
	double parentAmt;					//amount of parental savings contribution
	


	//calculate amount used for savings bond
	savingsAmt = incomeAfterExpenses * SAVINGS_PERCENT;

	//display money used for savings bond
	cout << setw(22) << left << "Savings Bonds:";
	cout << setw(2) << " $";
	cout << setw(8) << right << savingsAmt << endl;

	//calculate amount of parental savings contribution
	parentAmt = savingsAmt * PARENT_SAVINGS;

	//display amount of parental savings contribution
	cout << setw(22) << left << "Savings Bonds/Parents:";
	cout << setw(2) << " $";
	cout << setw(8) << right << parentAmt << endl;	
}