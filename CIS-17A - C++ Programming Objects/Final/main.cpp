#include"P6Loader.h"

int main()
{
	color** img;

	P6Loader loader;
	cout<< "created loader\n";
	img = loader.loadimage("domo_blur.ppm");
	cout << " file loaded\n";

	loader.saveimage("newImage.ppm", img, loader.width, loader.height);
	cout << " file saved\n";
}