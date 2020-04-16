#include "def.h"

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
    pInitMan->getName = getName;
    pInitMan->setName = setName;
    pInitMan->getAge = getAge;
    pInitMan->setAge = setAge;
    pInitMan->doWork = doWork;
}
void oop(void)
{
    man man;
    pman = &man;
    init_struct(pman);
    man.setName("Hoang");
    man.setAge(26);
    man.getName();
    man.getAge();
    man.doWork();
}
