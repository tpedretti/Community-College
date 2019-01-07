#include "includeInfo.h"

#ifndef _OPENFILE_H_
#define _OPENFILE_H_

class openAnimalFile {
private:
	bool _openFileCheck;

protected:
	ifstream inFile;

public:
	bool openFile(bool openFileCheck) {
		inFile.open("animaldossier.txt");
		if(inFile.fail()) {
			return false;
		}
		else {
			return true;
		}
	}
	void checkFail(bool openFileCheck) {
		if(openFileCheck == false) {
			cout << "File failed to open stopping program now... \n";
			exit(0);
		}
	}
	void getAnimalAmount(int amountofAnimals) {
		inFile >> amountofAnimals;
	}
};
#endif