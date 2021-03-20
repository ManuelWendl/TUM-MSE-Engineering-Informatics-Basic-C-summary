#include <stdio.h>
#define multiply(x,y) (x)*(y)
#define PI 3.14159265
#define circlearea(x) (PI*x*x)

int main(){
    int a = 12;
    int b = 10;
    printf("%d multiplied with %d = %d\n",a,b,multiply(a,b));
    float rad = 3;
    printf("For circle with radius %f this is the area: %f\n",rad,circlearea(rad));
}