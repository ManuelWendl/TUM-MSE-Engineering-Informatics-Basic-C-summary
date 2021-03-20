#include <stdio.h>
int main() {
    int x = 2;
    int y = x << 1;
    printf("%d -> %d \n", x, y);
    y = x << 2;
    printf("%d -> %d \n",x, y);
    int z = y >> 1;
    printf("%d -> %d \n",y, z);
}