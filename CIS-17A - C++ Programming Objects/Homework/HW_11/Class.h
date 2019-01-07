#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Algorithms 
{
private:
	int _i;
	int _j;

public:
	Algorithms() {}
	Algorithms(int i, int j) {
		_i = i;
		_j = j;
	}
	~Algorithms() {}
	/*bool function(int i,int j) {
		return (i<j); 
	}*/
	bool operator() (int i, int j) { 
	  return (i<j);
  }

};