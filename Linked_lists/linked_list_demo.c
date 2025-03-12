#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *p; // this will be created in the stack

    p = malloc(sizeof(struct node));

    printf("Size of p %d", sizeof(struct node));
}
