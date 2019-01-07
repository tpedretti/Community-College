#include <iostream>
#include <new>
#include <cstdlib>
#include "DZero.h"

double quotient(double numerator, double denominator) {
   if (denominator == 0)
      throw DZero();
   return numerator / denominator;
} 
void customNewHandler() {                                        
   cerr << "Bad Allc was called";
   abort();                              
} 

int main()
{
	char answer = 'Y';
	double numerator;	
	double denominator;	
	double result;
	double *ptr[50];

	set_new_handler(customNewHandler);

	while (toupper(answer)=='Y') { 
		cout << "Enter two numbers:\n";
	    cout << "Numerator:  ";
		cin >> numerator;
		cout << "Denominator:  ";
		cin >> denominator;

		try {
			result = quotient( numerator, denominator );
			cout << "The quotient is: " << result << endl;
		}
		catch (DZero &dZero) {
			cout << "Exception occurred: " << dZero.what() << endl;
		}

		for (int i = 0; i < 50; i++) {
			ptr[i] = new double[50000000];
			cout << "ptr[" << i << "] points to 50,000,000 new doubles!\n";
		}
	}
}	
