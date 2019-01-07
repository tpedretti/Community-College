
#include"ImageLoader.h"

#ifndef _IMAGE_H_
#define _IMAGE_H_


class Image
{
public:
	Image();
	Image(const Image& copy);
	~Image( );
	void loadimage(string filename);
	void saveimage(string filename);
	Image superimpose(const Image& ontop, color mask);
	int getwidth( );
	int getheight( );
	Image operator=(const Image& );
protected:
	color** pixels;
	int width;
	int height;
	ImageLoader* loader;




};






#endif _IMAGE_H_