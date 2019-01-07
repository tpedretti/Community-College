#include"P6Loader.h"

/*
int** ary = new int*[sizeX];
for(int i = 0; i < sizeX; ++i)
    ary[i] = new int[sizeY];
	*/

color** P6Loader::loadimage(string filename)
{
	//convert p6 of a ppm file to ascii or numbers
	//open filename, read in height and width, read and dump uneeded lines, 
	//read in red green blue values. close file, return temporary color array.
	
	ifstream inFile;
	string s;
	//char *temp;
	int numLevels;

	// ios::binary because it is a data file
	inFile.open(filename, ios::binary);
	if (inFile.fail())
	{
		cout << "Error Opening File!\n\n";
	}
	cout << "file opened\n";
		// read in the ppm header
	inFile >> s;
	if (s != "P6") 
		cout << "Not a valid PPM image" << endl;

	inFile.ignore();
	getline(inFile, s);
	cout << s << endl;
	inFile >> width >> height >> numLevels;
	inFile.ignore();
	cout << "file variables saved\n" << width << height  << numLevels << endl;
	system("pause");

	//temp = new char[width*height*3];
	//color** img = new color[width][height];
	color** img = new color*[height];

	for(int i = 0; i< height; i++)
	{
		img[i] = new color[width];
	}
	cout << "created pixel array\n";
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			//char* temp = new char[1];
			//inFile.read(temp, 1);
			//cout << temp[1] << endl;
			//img[i][j].r = temp[1];
			//inFile.read(temp, 1);
			//img[i][j].g = temp[1];
			//inFile.read(temp, 1);
			//img[i][j].b = temp[1];
			//cout << img[i][j].r << "  " <<img[i][j].g << "  " << img[i][j].b << endl;
			char temp;
			inFile.get(temp);
			img[i][j].r = (int)temp;
			inFile.get(temp);
			img[i][j].g = (int)temp;
			inFile.get(temp);
			img[i][j].b = (int)temp;
			cout << "pixel " << "["<<i<<"]"<<"["<<j<<"]" << " loaded\n" ;
			cout << img[i][j].r << "  " <<img[i][j].g << "  " << img[i][j].b << endl; 
			inFile.ignore();
		}
	}
	system("pause");


	// read in the image data to temp
	//inFile.read(width*height*3);
	inFile.close();
	return img;
}
void P6Loader::saveimage(string filename, color** img, int w, int h)
{
	cout << "begining file saving\n"; 
	ofstream outFile;
	outFile.open(filename, ios::out | ios::binary);

	if (outFile.fail())
	{
		cout << "Error Opening File!\n\n";
	}
	cout << "file opend\n";
	//
	//
	//
	//

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			char buffer[3];

			buffer[0] = img[i][j].r;
			buffer[1] = img[i][j].g;
			buffer[2] = img[i][j].b;
			outFile.write(buffer, sizeof(char)*3);
		}
		outFile << endl;
	}
	outFile.close();
}


/*

    Open the file
    read until the first white space and check you got P6. Then skip other white-spaces.
    read until the next white space, convert your buffer to an integer width. Then skip other white-spaces
    read until the next white space, convert your buffer to an integer height. Then skip other white-spaces
    Allocate a 2D array of integers in the size of height*width
    read the max-val
    read line by line and fill the array



*/