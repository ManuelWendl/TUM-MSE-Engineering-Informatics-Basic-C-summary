# include <stdio.h>

int main(){
// Pseudo Code
    switch (expression) {
        case case_expression1:  statement1; //default will also  be executed
        case case_expression2:  statement2;
        break; //default will not be executed because of break
        default: statement3;
    }
// Example
    int a = 5;
    int b = 6;

    switch (a==b) {
        case 1: printf("a equals b");
                break;
        default:
            switch (a<b) {
                case 1: printf("a smaller than b");
                case 0: printf("a greater than b");
            }
    }
}