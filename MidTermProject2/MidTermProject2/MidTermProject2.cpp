// Mickie Blair
// CIST 2361 - CRN 63227
// MidTerm Project - Project 2

#include <iostream>
#include <iomanip>

using namespace std;

double calcIncome(double, double);
double calcNetIncome(double);
double calcExpenses(double);
void getSavingsContribution(double, double);
void calcSavingsZero(double);
void calcSavingsLess25(double, double, double);
void calcSavingsGreater25(double, double, double);


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
		<< "- Money spent to buy savings bonds (Amount varies- 0%, <25%, >25%)\n"
		<< "- Money parents spent on buying additional savings bonds\n"
		<< "  (depends on user amount)\n"
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

	//get savings bonds contribution
	getSavingsContribution(incomeAfterExpenses, netIncome);

	//call function to calculate savings bond contributions (user and parents)
	//calcSavingsBond(incomeAfterExpenses);

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

//function for savings bonds contribution
void getSavingsContribution(double incomeAfterExpenses, double netIncome)
{
	double savingsPercent;	//variable for user input of savings contribution

	//display blank line
	cout << endl;

	//ask user for the percent they wish to use to buy savings bonds
	cout << "Percent for Savings Bonds (25% - Enter 25): ";
	cin >> savingsPercent;

	//if - else if statement to call functions for various contributions
	if (savingsPercent == 0)
		calcSavingsZero(incomeAfterExpenses);
	else if (savingsPercent > 0 && savingsPercent < 25)
		calcSavingsLess25(savingsPercent, netIncome, incomeAfterExpenses);
	else if (savingsPercent >= 25)
		calcSavingsGreater25(savingsPercent, netIncome, incomeAfterExpenses);

}

//function to calculate and display amount used on savings and parental savings contribution 
//when user contribution is zero percent
void calcSavingsZero(double incomeAfterExpenses)
{
	const double PARENT_SAVINGS = .01;	//constant - parental contribution 1% of income after expenses
	double parentAmt;					//amount of parental savings contribution

	//display blank line
	cout << endl;

	//display user contribution to savings bond as zero
	cout << setw(22) << left << "Savings Bonds/Student:";
	cout << setw(2) << " $";
	cout << setw(8) << right << 0.00 << endl;

	//calculate parental contribution to savings bonds
	parentAmt = incomeAfterExpenses * PARENT_SAVINGS;

	//display amount of parental savings contribution
	cout << setw(22) << left << "Savings Bonds/Parents:";
	cout << setw(2) << " $";
	cout << setw(8) << right << parentAmt << endl;
}

//function to calculate and display amount used on savings and parental savings contribution 
//when user contribution is greater than zero but less than 25% of net income
void calcSavingsLess25(double savingsPercent, double netIncome, double incomeAfterExpenses)
{
	const double PARENT_NET = .25;		//constant - parental contribution $0.25 per dollar of net income contribution
	const double PARENT_SAVINGS = .01;	//constant - parental contribution 1% of income after expenses

	double savingsAmt;					//amount used for savings bond
	double parentAmt;					//amount of parental savings contribution

	//display blank line
	cout << endl;

	//calculate amount used for savings bond
	savingsAmt = netIncome * (savingsPercent/100);

	//display money used for savings bond
	cout << setw(22) << left << "Savings Bonds/Student:";
	cout << setw(2) << " $";
	cout << setw(8) << right << savingsAmt << endl;

	//calculate amount of parental savings contribution
	parentAmt = (savingsAmt * PARENT_NET) + (incomeAfterExpenses * PARENT_SAVINGS);

	//display amount of parental savings contribution
	cout << setw(22) << left << "Savings Bonds/Parents:";
	cout << setw(2) << " $";
	cout << setw(8) << right << parentAmt << endl;
}

//function to calculate and display amount used on savings and parental savings contribution 
//when user contribution is greater than/equal to 25% of net income
void calcSavingsGreater25(double savingsPercent, double netIncome, double incomeAfterExpenses)
{
	const double PARENT_NET = .40;		//constant - parental contribution $0.40 per dollar of net income contribution
	const double PARENT_SAVINGS = .02;	//constant - parental contribution 2% of income after expenses

	double savingsAmt;					//amount used for savings bond
	double parentAmt;					//amount of parental savings contribution

	//display blank line
	cout << endl;

	//calculate amount used for savings bond
	savingsAmt = netIncome * (savingsPercent / 100);

	//display money used for savings bond
	cout << setw(22) << left << "Savings Bonds/Student:";
	cout << setw(2) << " $";
	cout << setw(8) << right << savingsAmt << endl;

	//calculate amount of parental savings contribution
	parentAmt = (savingsAmt * PARENT_NET) + (incomeAfterExpenses * PARENT_SAVINGS);

	//display amount of parental savings contribution
	cout << setw(22) << left << "Savings Bonds/Parents:";
	cout << setw(2) << " $";
	cout << setw(8) << right << parentAmt << endl;
}
