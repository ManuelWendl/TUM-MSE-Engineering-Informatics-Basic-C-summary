#include <stdio.h>
#include <stdlib.h>

void anagram(long int number1, long int number2){
    long int i = 1;
    while(number1 - i >= 0)
        i*=10;
    long int j = 1;
    while(number2 - j >= 0)
        j*=10;
    if(j!=i) {
        printf("Not an anagram!\n");
        return;
    }else{
        for(long int ii=i; ii>=10; ii/=10){
            int bool = 0;
            for(long int k=j;k>=10; k/=10){
                if((number1%ii-number1%(ii/10))/(ii/10)==(number2%k-number2%(k/10))/(k/10)){
                    bool=1;
                    number2 = number2%(k/10) + (number2%(j)-number2%(k))/10;
                    j/=10;
                    break;
                }
            }
            if(bool!=1){
                printf("No Anagram!\n");
                return;
            }
        }
    }
    printf("Is an Anagram!\n");
}

int main() {
    char buffer1[21] = {0};
    printf("Enter first number with less than 20 digits\n");
    scanf("%21s", buffer1);
    fflush(stdin);
    long int number1 = atoi(buffer1);
    char buffer2[21] = {0};
    printf("Enter second number with less than 20 digits\n");
    scanf("%21s", buffer2);
    fflush(stdin);
    long int number2 = atoi(buffer2);
    printf("%ld,%ld\n", number1,number2);
    anagram(number1,number2);
}