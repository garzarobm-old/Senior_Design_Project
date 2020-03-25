/* to implement practice calls C++ */


#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdint.h>
#include "practiceCall.h"


/*function implementation from a class*/
F::F(int32_t a){
	k = a <<1;

}
F::~F()
{


	k = 0;

}

std::string 
F::toString()
{
	std::ostringstream os;
	os << "Foo is currently: " << this->k <<std::endl;
	return( os.str() );



}
int f(int i ){



}
void *getF(int32_t a ){
	F *out(new F(a) );
	return ( reinterpret_cast< void* > (out) );

}

void destroyF( void* f)
{
	delete( reinterpret_cast< F* >( f ) );
}

void printString( void *f ) 
{

	std::string s = reinterpret_cast< F* >( f )->toString();
	std::cout << s;
}



