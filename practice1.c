#include<stdio.h>
int add(int a){
    if (a == 3){
        return 0;
    }
    printf("%d ",a);
    add(a-1);
}

void main(){
    add(10);
}