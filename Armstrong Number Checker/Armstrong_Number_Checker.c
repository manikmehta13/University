#include <stdio.h>
#include <math.h>

void main(){
 int num,sum=0,copy,power=0;
 printf("Enter a number to check: ");   
 scanf("%d", &num);
 copy=num;
 while(copy!=0){
    power++;
    copy = copy/10;
 }

 copy=num;

 while (copy!=0)
 {
    sum+=pow((copy%10),power);
    copy = copy/10;
 }

 if (num==sum)
 {
    printf("The number is an Armstrong Number");
}
else{
     printf("The number is not an Armstrong Number");
 }
}