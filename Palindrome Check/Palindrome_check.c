# include <stdio.h>
 
void main(){
    int num, reverse = 0, count = 0, copy;
    printf("Enter a number to check: ");
    scanf("%d",&num);
    copy = num;

    while(num!=0){
        
        if(num != 0){
            reverse = (reverse*10) + (num % 10);
            num/=10; 
        }

        else{
            printf("Error");
        }

    }

    if (reverse == copy)
    {
        printf("The given number is a Palindrome");
    }

    else
    {
        printf("The given number is not a Palindrome");
    }
    
    
}