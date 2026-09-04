#include <stdio.h>
#include <conio.h>

void main(){

int a=0,b=1,c,num;
c=a+b;
printf("Enter the no of terms: ");
scanf("%d",&num);
printf("%d ,",a);
printf("%d ,",b);
while((num-2)!=0){
printf("%d ,",c);
a=b;
b=c;
c=a+b;
num--;}
getch();
}

