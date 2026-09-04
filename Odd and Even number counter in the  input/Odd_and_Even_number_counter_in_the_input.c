#include <stdio.h>

void main(){
    int num,odd=0,even=0;
    printf("Enter a number to calculate the no. of even and odd numbers: ");
    scanf("%d",&num);
    while(num!=0){
        if ((num%10)%2 == 0)
        {
            even++;
        }
        else{
            odd++;
        }
        num/=10;
    }

    printf("Even: %d\n", even);
    printf("Odd: %d", odd);
}