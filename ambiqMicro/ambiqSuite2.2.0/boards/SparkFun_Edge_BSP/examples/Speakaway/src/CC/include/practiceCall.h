#include <stdint.h>

#ifdef __cplusplus
/* class definitions for C++ header definition */
class F
{

public:
	F(int32_t a);
	~F();
	std::string toString();
private: 
	int32_t k;





};



#endif

/* END OF CLASS DEFINITIONS */




/*C++ declaration in a header file for C files*/

#ifdef __cplusplus
extern "C" {

#endif



int f(int i);
void* getF(int32_t a );
void destroyF(void  *F );
void printString(void *F);

#ifdef __cplusplus
}
#endif
