#include <stdio.h>

int sum(int a,int b)
{
    return a+b;
}
int sub(int a, int b)
{
    return a-b;
}
int mult(int a, int b)
{
    return a*b;
}
int div(int a, int b)
{
    return a/b;
}
int getIndex(char input)
{
    switch(input)
    {
    case '+':
        return 0;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 3;
    default:
        printf("Operator error!");
        return -1;
    }
}

void array_function_pointer(void)
{
    int x, y, result, index;
    char s;
    int (*cal[4])(int, int);
    cal[0]=sum;
    cal[1]=sub;
    cal[2]=mult;
    cal[3]=div;
    printf("Input x, operator , y: ______exam: 1 + 1\n");
    // check %c, get space
    scanf("%d%s%d",&x,&s,&y);
    index = getIndex(s);
    if (index == -1)
        return;
    if (index == 3 && y == 0)
    {
        printf("Div with y = 0 error.\n");
        return;
    }
    result = cal[index](x,y);
    printf("Result: %d\n",result);
}
