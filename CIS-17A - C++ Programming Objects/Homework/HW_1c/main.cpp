//========================================
// File: HW_1c
// =======================================
// Programmer: Taylor Pedretti
// Date: 2/22/2011
// Class: CIS 17A
// Instructor: Dennis Rainey
// =======================================
#include <iostream>
#include <iomanip>
#include <cmath>

void getData(float & rate, float & loan);
float calcInterest(float rate, float loan);
void displayResult(float & rate, float & loan, float & interest);

using namespace std;

int main()
{
	float rate = 0.0;
	float loan = 0.0;
	float interest = 0.0;

	getData(rate, loan);
	interest = calcInterest(rate, loan);
	displayResult(rate, loan, interest);


	system("PAUSE");
	return 0;
}

void getData(float & rate, float & loan)
{
	cout << "Please enter the annual interest rate: ";
	cin >> rate;
	cout << "Please enter the loan amount: ";
	cin >> loan;
}

float calcInterest(float rate, float loan)
{
	float interest;
	interest = ((rate/100) * loan)/12;
	return interest;
}

void displayResult(float & rate, float & loan, float & interest)
{
	cout << "The first month's interest on $" << loan << " at " << rate << " percent, equals $" << setprecision (5) << interest << ".\n";
}