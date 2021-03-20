#include <stdio.h>

int main(){
// Pseudo Code
    if(expression1){
        statement1;
    }else if(expression2){
        statement2;
    }else{
        stetement3;
    }
// Example
    int a = 3;
    int b = 5;

    if(a==b){
        printf("a equals b");
    }else if(a<b){
        printf("a smaller than b");
    }else{
        printf("a greater than b");
    }
}