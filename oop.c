#include "def.h"
#include <stdlib.h>
typedef struct man
{
    char name[10];
    int age;
    char* (*getName)();
    void (*setName)(char*);
    int (*getAge)();
    void (*setAge)(int);
    void (*doWork)();
}man;

man *pman;

static char *getName()
{
    printf("%s\n",pman->name);
    return pman->name;
}
static void setName(char*s)
{
    strcpy(pman->name,s);
}
static int getAge()
{
    printf("%d\n",pman->age);
    return pman->age;
}
static void setAge(int a)
{
    pman->age = a;
}
static void doWork()
{
    printf("I'm working!\n");
}
static void init_struct(man *pInitMan)
{
    pman = pInitMan;
    pInitMan->getName = getName;
    pInitMan->setName = setName;
    pInitMan->getAge = getAge;
    pInitMan->setAge = setAge;
    pInitMan->doWork = doWork;
}

void oop(void)
{
    int n=10;
    man *ptrMan;
    ptrMan = (struct man*)malloc(n* sizeof(man));
    for (int i=0;i<9;i++)
    {
        init_struct(ptrMan+i);
        (ptrMan+i)->setName("Hoang");
        (ptrMan+i)->setAge(26);
    }
    init_struct(ptrMan+9);
    (ptrMan+9)->setName("Thanh");
    (ptrMan+9)->setAge(26);

    init_struct(ptrMan);
    ptrMan->getName();
    ptrMan->getAge();
    ptrMan->doWork();

    init_struct(ptrMan+9);
    ptrMan[9].getName();
    ptrMan[9].getAge();
    ptrMan[9].doWork();
}
