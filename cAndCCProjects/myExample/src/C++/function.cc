//C++ code 

#include <cstdio> //okay because included from system

/*for not included in the system
/* 

extern "C" {
	#include "myCHeader.h"

}

*/


extern "C" void f(int); //one way




extern "C" { 		//another way 

	int g(double);
	double h();

};


void f(int i)
{

	std::printf("Hello from f function\n");	

}
