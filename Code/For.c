#include <stdio.h>

int main(){
// Pseudo Code
    for (assignment;condition;step){
        statements;
    }
// Example
    float sum = 0;
    int n = 10;
    for (int i=1;i<=n;i++){
        sum = sum + 1/(float)i;
    }
    printf("n-th partial sum = %f",sum);
}