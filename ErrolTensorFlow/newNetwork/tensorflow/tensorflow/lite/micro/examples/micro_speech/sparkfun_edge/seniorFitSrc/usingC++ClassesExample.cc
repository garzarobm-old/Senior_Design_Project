
/* to implement practice calls C++ */


#include <stdint.h>
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/include/usingC++ClassesExample.h"


/*function implementation from a class*/
F::F(int32_t a){
	k = a <<1;

}

/* function for destroying (may not need) */
F::~F()
{


	k = 0;

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

}




