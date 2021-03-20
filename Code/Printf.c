#include <stdio.h>

int main(){
    int a = -6;
    char b = 120;
    float c = 3;
    double d = 5.36;

    printf("Value of a: %d \n",a); //-> Value of a: -6
    printf("Value of a: %u \n",a); //-> Value of a: 4294967290
    printf("Value of a: %x \n",a); //-> Value of a: fffffffa
    printf("Value of b: %c \n",b); //-> Value of b: x
    printf("Value of b: %d \n",b); //-> Value of b: 120
    printf("Value of c: %f \n",c); //-> Value of c: 3.000000
    printf("Value of c: %d \n",c); //-> Value of c: 73896
    printf("Value of d: %f \n",d); //-> Value of d: 5.360000
    printf("Value of a: %d and b: %c \n",a,b); //-> Value of a: -6 and b: x
}
