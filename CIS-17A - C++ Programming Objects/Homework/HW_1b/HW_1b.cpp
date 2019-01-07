//========================================
// File: HW_1b
// =======================================
// Programmer: Taylor Pedretti
// Date: 2/22/2011
// Class: CIS 17A
// Instructor: Dennis Rainey
// =======================================
#include <iostream>
float getFirstNum();
float getSecondNum();
float calcSum(float num1, float num2);
void displaySum(float & num1, float & num2, float & sum);

using namespace std;

int main()
{
	float num1 = 0.0;
	float num2 = 0.0;
	float sum = 0.0;

	num1 = getFirstNum();
	num2 = getSecondNum();
	sum = calcSum(num1, num2);
	displaySum(num1, num2, sum);

	system("PAUSE");
	return 0;
}

float getFirstNum()
{
	float num1;
	cout << "Please enter the first number: ";
	cin >> num1;
	return num1;
}

float getSecondNum()
{
	float num2;
	cout << "Please enter the first number: ";
	cin >> num2;
	return num2;
}

float calcSum(float num1, float num2)
{
	float sum;
	sum = num1 + num2;
	return sum;
}

void displaySum(float & num1, float & num2, float & sum)
{
	cout << "The sum of " << num1 << " and " << num2 << " is " << sum << ".\n";
}