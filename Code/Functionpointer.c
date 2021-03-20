#include <stdio.h>

// Pseudo Code
    return_type *varaible_name(parameters){
    ...
    }
// Example
    int *f_pointer(int *a, int *b){
        int x = *a + *b;
        int *ptr = &x;
        return ptr;
    }
    int main(){
        int a = 1;
        int b = 2;
        printf("%d",*f_pointer(&a,&b));
    }