#include <stdio.h>
int main(){
    // Even or Odd numbers
    int x = -19;
    (x & 1) ? printf("Odd\n") : printf("Even\n");

    // Numbers of power of two
    int y = 8;
    if((y & (y-1))==0)
        printf("%d is a power of two\n", y);

    // Swapping two numbers without temp variable
    int a = 4, b = 1;
    printf("%d and %d\n", a, b);
    a^=b;
    b^=a;
    a^=b;
    printf("%d and %d\n", a, b);
}