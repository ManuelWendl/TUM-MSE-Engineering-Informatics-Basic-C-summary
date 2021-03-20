#include <stdio.h>
static int a = 2; //only accessible in this c file

int sum(){
    static int sum = 0; //value of sum stays 55
    for(int j=1;j<=10;j++){
        sum = sum + j;
    }
    return sum;
}

int main(){
    printf("Sum first run: %d\n",sum());
    printf("Sum second run: %d\n",sum());
}