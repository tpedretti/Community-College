#include <iostream>
#include <string>
#include <fstream>


using namespace std;

struct Animals
{
	string name;
	int qty;
	int consumption;
};


int main()
{
	//Student struct
	
	Animals *animalsInfo;
	Animals *mostFoodConsumed;
	Animals *leastFoodConsumed;

	ifstream input;
	int size = NULL;
	int total = NULL;
	int nSmallestIndex;
	int outputOrder = 1;
	int average = NULL;


	input.open("animalInfo.txt", ifstream::in);

	if(input.fail()) {
		cout << "fail!!!!!";
		return 0;
	} 

	input >> size;

	animalsInfo = new Animals[size];
	
	for(int i = 0; i < size; i++) {
		input.ignore();

		getline(input, animalsInfo[i].name);

		input >> animalsInfo[i].qty;
		//getline(input, animalsInfo[i].qty);

		input >> animalsInfo[i].consumption;
		//getline(input, animalsInfo[i].consumption);

	}

	for(int i = 0; i < size; i++) {
		cout << "Name: " << animalsInfo[i].name << endl;
		cout << "QTY: " << animalsInfo[i].qty << endl;
		cout << "Consumption: " << animalsInfo[i].consumption << endl;
		cout << endl;
	}


	//Finds the total good consumed
	for(int i = 0; i < size; i++) {
		total += animalsInfo[i].consumption;
	}
	average = total / size;

	cout << "Total Food consumed: " << total << endl;

	//Ranks for Most food consumed by
	mostFoodConsumed = &animalsInfo[0];

	for(int nStartIndex = 0; nStartIndex < size; nStartIndex++)	{
		// nSmallestIndex is the index of the smallest element
		// we've encountered so far.
		nSmallestIndex = nStartIndex;
		
		// Search through every element starting at nStartIndex+1
		for(int nCurrentIndex = nStartIndex + 1; nCurrentIndex < size; nCurrentIndex++)	{
			// If the current element is smaller than our previously found smallest
			if (animalsInfo[nCurrentIndex].consumption < animalsInfo[nSmallestIndex].consumption/*, mostFoodConsumed->consumption*/) {
				// Store the index in nSmallestIndex
				nSmallestIndex = nCurrentIndex;
				//mostFoodConsumed = &animalsInfo[nCurrentIndex];
			}
		}
		// Swap our start element with our smallest element
		swap(animalsInfo[nStartIndex].name, animalsInfo[nSmallestIndex].name);
		swap(animalsInfo[nStartIndex].qty, animalsInfo[nSmallestIndex].qty);
		swap(animalsInfo[nStartIndex].consumption, animalsInfo[nSmallestIndex].consumption);
		
	}

	cout << "Most food consumed by:\n";
	for(int i = size - 1; i > 5; i--) {
		cout << "\t" << outputOrder++ << ". " << animalsInfo[i].name << " " << animalsInfo[i].consumption <<endl;
	}

	outputOrder = 1;

	cout << "Least food consumed by:\n";
	for(int i = size - 6; i > 0; i--) {
		cout << "\t" << outputOrder++ << ". " << animalsInfo[i].name << " " << animalsInfo[i].consumption <<endl;
	}

	cout << "The average of those three numbers is: " << average << endl;

	input.close();
	system("PAUSE");
	return 0;
}