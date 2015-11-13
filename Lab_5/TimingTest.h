#include "System.h"

struct byte8Test {
	int test[2];
};

struct byte128Test {
	int test[32];
};

double add32BitsInt(void);
double mul32BitsInt(void);
double div32BitsInt(void);

double add64BitsInt(void);
double mul64BitsInt(void);
double div64BitsInt(void);

double copy8ByteStruct(void);
double copy128ByteStruct(void);

void timeTest(void);
