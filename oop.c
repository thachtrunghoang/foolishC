#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int n=2;
    man *ptrMan;
    ptrMan = (struct man*)malloc(n* sizeof(man));

    init_struct(ptrMan);
    ptrMan[0].setName("Ta");
    ptrMan[0].setAge(26);

    init_struct(ptrMan+1);
    ptrMan[1].setName("Thanh");
    ptrMan[1].setAge(26);

    init_struct(ptrMan);
    ptrMan[0].getName();
    ptrMan[0].getAge();
    ptrMan[0].doWork();

    init_struct(ptrMan+1);
    ptrMan[1].getName();
    ptrMan[1].getAge();
    ptrMan[1].doWork();

    free(ptrMan);
}
