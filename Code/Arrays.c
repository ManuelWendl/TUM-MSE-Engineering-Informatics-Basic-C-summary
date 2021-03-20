#include <stdio.h>
//Pseudo Code
data_type array_name[size];
// Example
int main(){
    int example[3] = {1, 2, 3}; // Initializing
    example[0]=example[2]; // Setting the first element
                             // to value of third.
    for(int i=0;i<3;i++){
        printf("example[%d] = %d\n",i,example[i]);
    }
}