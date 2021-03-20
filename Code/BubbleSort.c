#include <stdio.h>

void bubble_sort(int array[], int size){
    if(size == 0)
        return;
    for(int i=0;i<size-1;i++){
        if(array[i]>array[i+1]) {
            int temp = array[i];
            array[i]=array[i+1];
            array[i+1]=temp;
        }
    }
    bubble_sort(array,size-1);
}

int main(){
    int array[5]={9, 6, 4, 7, 1};
    for(int i=0;i<5; i++){
        printf("%d\t",array[i]);
    }
    printf("\n");
    bubble_sort(array,5);

    for(int i=0;i<5; i++){
        printf("%d\t",array[i]);
    }
}