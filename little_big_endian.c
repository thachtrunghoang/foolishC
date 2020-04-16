#include "def.h"

// 333 = 256 + 77
// 255 = 0xFF, 256 = 0x100

union test
{
    int a;
    char b[2];
};

void little_big_endian(void)
{
    union test valueTest;
    valueTest.a = 333;
    if (valueTest.b[0]==77 && valueTest.b[1]==1)
    {
        printf("This is little-endian!");
    }
    else
    {
        printf("This is big-endian!");
    }
}

