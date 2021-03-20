#include <stdio.h>

void tocapital(char array[]){ // array with variable length.
    int i = 0;
    while(array[i]!=0){
        if(array[i]<123 && array[i]>96) { // Range of small letters
            array[i] -= 32; // Difference capital small in Ascii
        }
        i++;
    }
}

int main(){
    char string[] = "Good Luck In The Exam!";
    printf("Before tocapital(): %s\n",string);
    tocapital(string);
    printf("After tocapital(): %s\n",string);
}