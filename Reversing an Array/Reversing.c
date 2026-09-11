#include<stdio.h>

void main(){
    int arr[] = {1,2,3,4,5,6,7};
    int elements = sizeof(arr)/sizeof(arr[0]);
    int value = elements;
    int reversed_arr[sizeof(arr)/sizeof(arr[0])];
    for(int i=0;i<value;i++){
        reversed_arr[i] = arr[elements-1];
        elements--;
    }
    for (int i = 0; i<value; i++) {
        printf("%d ", reversed_arr[i]);
    }
}