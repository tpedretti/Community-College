//========================================
// File: HW_2a
// =======================================
// Programmer: Taylor Pedretti
// Date: 3/1/2011
// Class: CIS 17A
// Instructor: Dennis Rainey
// =======================================
#include <iostream>

void getScores(double testScores[]);
void showMenu();
char getChoice();
void displayResult(char answer, double testScores[], double average);

using namespace std;

const int SIZE = 5;

int main()
{
	double testScores[SIZE] = {0};
	char answer;
	double average = 0;

	getScores(testScores);
	showMenu();
	answer = getChoice();
	displayResult(answer,testScores,average);

	system("PAUSE");
	return 0;
}

void getScores(double doubletestScores[])
{
	cout << "Enter 5 test scores:\n";
	for(int i = 0; i < SIZE; i++){	
	cin >> doubletestScores[i];
	}
	system("CLS");
}

void showMenu()
{
	cout << "A.) Calculate the average of the test Scores.\n";
	cout << "B.) Display all test Scores.\n";
}

char getChoice()
{
	char answer;
	cout << "Enter your choice: ";
	cin >> answer;
	return answer;
}

void displayResult(char answer, double testScores[], double average)
{
	system("CLS");
	if(toupper(answer) == 'A') {
		 for(int i = 0; i < SIZE; i++) {
			 average += testScores[i];
		 }
		 cout << "The average is " << average/SIZE << ".\n";
	}
	if(toupper(answer) == 'B') {
		for(int i = 0; i < SIZE; i++) {
			cout << testScores[i] << "\t";
		}
		cout << endl;
	}
	else
		cout << "Invalid Entry!\n";
}