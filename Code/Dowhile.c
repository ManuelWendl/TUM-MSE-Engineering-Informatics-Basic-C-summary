#include <stdio.h>

int main(){
// Pseudo Code
    do {
        statements;
    }while (expression);
// Example
    char grade;
    do {
        printf("Please enter your grade (number between 1 and 6):\n");
        grade = getchar();
        getchar();
    }while(grade < '1'|| grade > '6');
}