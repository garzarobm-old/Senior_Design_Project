#include <stdlib.h>
#include "practiceCall.h"



int main (int argc, const char **argv){
	
	void *FObjectReturned = getF(1);
	int number = f(2);
	printf("calling string returned from practiceCall = %d", FObjectReturned);	
	return 0;




}
