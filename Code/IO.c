#include <stdio.h>

int main(){
    int size = 10;
// gets()
    char buffer1[size];
    gets(buffer1);
    printf("Scanned input: %s\n",buffer1);
// fgets()
    fflush(stdin);
    char buffer2[size];
    fgets(buffer2,size,stdin);
    printf("Scanned input: %s\n",buffer2);
// scanf()
    fflush(stdin);
    char buffer3[size];
    scanf("%9s",buffer3);
    printf("Scanned input: %s\n",buffer3);
}