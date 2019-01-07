#include"Image.h"

Image::Image()
{
	pixels = NULL;
	width = 0;
	height = 0;
	loader = NULL;
}
Image::Image(const Image& copy)
{
	pixels = copy.pixels;
	width = copy.width;
	height = copy.height;
	loader = copy.loader;

}
Image::~Image( )
{
	delete pixels;
}
void Image::loadimage(string filename)
{
	pixels = loader->loadimage(filename);
}
void Image::saveimage(string filename)
{
	loader->saveimage(filename, pixels, width, height);
}
