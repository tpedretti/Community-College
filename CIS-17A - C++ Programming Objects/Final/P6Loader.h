#include"ImageLoader.h"


#ifndef _P6LOADER_H_
#define _P6LOADER_H_

class P6Loader : public ImageLoader
{
public:
	color** loadimage(string filename);
	void saveimage(string filename, color** img, int w, int h);


};



#endif _P6LOADER_H_