#include <stdio.h>
#include<stdlib.h>
void main()
{
    int *p;
    p = (int *)malloc(sizeof(int));

    int a = 100;
    int b = 300;
    *p = 200;

    printf("Address of p is %d\n", p);
    printf("value at p is %d\n", *p);

    printf("Addes of a is %d\n", &a);
    printf("Value of a is %d\n", a);
}