//#include "openFile.h"
#include "readFile.h"


int main()
{
	openAnimalFile animalInfo;
	readAnimalInfo *inAnimalInfo;

	bool checkInfo = NULL;
	int amountofAnimals = NULL;

	animalInfo.openFile(checkInfo);
	animalInfo.checkFail(checkInfo);

	inAnimalInfo = new readAnimalInfo[amountofAnimals];
	//inAnimalInfo.getAnimalAmount(amountofAnimals);

	for(int i = 0; i < amountofAnimals; i++) {
		input.ignore();
		//cout << "Enter your name: ";
		getline(inFile, inAnimalInfo[i].name);
		//input >> student[i].name;
		
		//cout << "Enter your ID: ";
		input >> student[i].id;
		
		//cout << "Enter your grade: ";
		input >> student[i].grade;
		
		//cout << "Enter your age: ";
		input >> student[i].age;
		
		//cout << "Enter your height: ";
		input >> student[i].height;
		//cin.ignore();
	}

	return 0;
}