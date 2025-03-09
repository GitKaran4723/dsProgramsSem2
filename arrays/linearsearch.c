#include<stdio.h>
int linearSearch(int arr[], int n, int key){
    for(int i = 0; i < n; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1; // element not found
}
int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int key = 40;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = linearSearch(arr, n, key);
    if(result != -1){
        printf("Element fount at %d\n", result);
    }
    else{
        printf("Element not found");
    }
}