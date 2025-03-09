#include<stdio.h>

int binarySearch(int arr[], int k, int s, int l){
    if (s>l){
        return -1;
    }
    int mid = (s+l)/2;
    if(arr[mid] == k){
        return mid;
    }
    else if(k < arr[mid]){
        return binarySearch(arr, k, s, mid - 1);
    }else{
        return binarySearch(arr, k, mid + 1, l);
    }
}

void main(){
    int arr [] = {1, 5, 8, 9, 11, 18, 20};
    int l = sizeof(arr)/sizeof(arr[0]);
    int s = 0;
    int key = 9;

    int res = binarySearch(arr, key, s, l-1);

    if(res == -1){
        printf("Element not found");
    }
    else{
        printf("Element found at %d", res);
    }

}