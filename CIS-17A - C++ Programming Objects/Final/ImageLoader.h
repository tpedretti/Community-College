#include"color.h"

#ifndef _IMAGELOADER_H_
#define _IMAGELOADER_H_

class ImageLoader
{
public:
	virtual color** loadimage(string filename)=0;
	virtual void saveimage(string filename, color** img, int w, int h)=0;

	int width;
	int height;
	string datatype;
	unsigned int maxval;


};

#endif _IMAGELOADER_H_