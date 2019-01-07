#include "openFile.h"
#include <fstream>

#ifndef _READFILE_H_
#define _READFILE_H_

class readAnimalInfo : openAnimalFile
{
private:
	int _amountOfAnimals;
	string _typeOfAnimal;
	int _qty;
	int _consumption;
public:
	readAnimalInfo();
	readAnimalInfo(int amountofAnimals, string typeOfAnimal) {
		_amountOfAnimals = amountofAnimals;
		_typeOfAnimal = typeOfAnimal;
	}
	~readAnimalInfo();
	void getAnimalAmount(int amountofAnimals) {
		inFile >> amountofAnimals;
	}
	void getInfo(int amountofAnimals, string typeOfAnimal);

};
#endif