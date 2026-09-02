# include <stdio.h>
 
void main(){
    int num, reverse = 0, count = 0;
    printf("Enter a number to reverse: ");
    scanf("%d",&num);

    while(num!=0){
        
        if(num != 0){
            reverse = (reverse*10) + (num % 10);
            num/=10; 
        }

        else{
            printf("Error");
        }

    }

    printf("The reversed number is: %d", reverse);
}