#include<stdio.h>
void numberPrint(int a){
    if (a<101){
        printf("%d\n", a);
        a++;
        return numberPrint(a);
    }
    return;
}
void main(){
    numberPrint(1);
}