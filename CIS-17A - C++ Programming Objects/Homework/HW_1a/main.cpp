//========================================
// File: HW_1a
// =======================================
// Programmer: Taylor Pedretti
// Date: 2/22/2011
// Class: CIS 17A
// Instructor: Dennis Rainey
// =======================================
#include <iostream>

float getScore();
char determineGrade(float score);
void displayGrade(float score, char grade);

using namespace std;

int main()
{
	float score;
	char grade;
	char again = 'y';

	while ((again == 'Y') || (again == 'y')) {

	score = getScore();
	grade = determineGrade(score);
	displayGrade(score, grade);

	cout << "Do it again? (Y/N)";
	cin >> again;
	}

	return 0;
}

float getScore()
{
	float score;
	cout << "Enter a test score: ";
	cin >> score;
	return score;
}

char determineGrade(float score)
{
	char grade;
	if (score >= 90) {
		grade = 'A';
	}
	else if (score >= 80) {
		grade = 'B';
	}
	else if (score >= 70) {
		grade = 'C';
	}
	else if (score >= 60) {
		grade ='D';
	}
	else
		grade ='F';
	return grade;
}

void displayGrade(float score, char grade)
{
	cout << score << " is a " << grade << ".\n";
}