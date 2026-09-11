#include <stdio.h>
void main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int value;
    int found_status = 0;
    printf("Enter a Value to search: ");
    scanf("%d", &value);
    for (int i = 0; i < size; i++)
    {
        if (value == arr[i])
        {
            found_status = 1;
        }
        
    }

    if (found_status == 1)
    {
        printf("Found!\n");
    }

    else{
        printf("Not Found!\n");
    }
    
}
