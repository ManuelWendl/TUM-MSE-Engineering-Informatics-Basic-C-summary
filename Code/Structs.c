#include <stdio.h>

struct example1{
    int a;
    double b;
}; // Initializing in main

struct example2 {
    int c;
    double d;
}e; // Directly Initializing all values = zero

int main() {
    struct example1 x = {10, 13.9};
    printf("struct x: %d and %f\n",x.a,x.b);
    printf("struct e before: %d and %f\n",e.c,e.d);
    e.c = 10;
    e.d = 13.9;
    printf("struct e after: %d and %f\n",e.c,e.d);
}