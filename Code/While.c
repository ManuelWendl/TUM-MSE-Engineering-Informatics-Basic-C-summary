# include <stdio.h>

int main(){
// Pseudo Code
   while (expression){
        statements;
    }
// Example
    float sum = 0;
    int i = 1;
    int n = 10;
    while (i<=n){
        sum = sum + 1/(float)i;
        i++;
    }
    printf("n-th partial sum = %f",sum);
}