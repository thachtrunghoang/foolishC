#include "def.h"
#define MATCH(a,b) (a##b)

void concatenation_operator(void)
{
    int var =10;
    printf("%d",MATCH(v,ar));
}
