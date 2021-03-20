#include <stdio.h>
#include <stdlib.h>
int main() {
    char buffer[21] = {0};
    printf("Enter a number with less than 20 digits\n");
    scanf("%21s",buffer);
    fflush(stdin);
    long int number = atoi(buffer);
    long int i = 1;
    while(number - i >= 0)
        i*=10;
    long int j = 10;
    while(i>j){
        if((number%i-number%(i/10))/(i/10)!=(number%j-number%(j/10))/(j/10)){
            printf("Not a palindrome\n");
            return 0;
        }
        i/=10;
        j*=10;
    }
    printf("It is a palindrome!\n");
}