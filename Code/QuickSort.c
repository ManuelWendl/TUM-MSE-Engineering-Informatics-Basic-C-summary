#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quicksort(int *array, int size){
    if(size<2){
        return;
    }
    int *pivot = array;
    int *ptr = array+1;
    int count = 0;

    while(ptr!=array+size){
        if(*ptr<*pivot){
            swap(ptr++,pivot++);
            count++;
        }else
            ptr++;
    }
    quicksort(array,count);
    quicksort(array+count,size-count);
}

int main(){
    int array[5]={9, 6, 4, 7, 1};
    quicksort(array,5);
    for(int i=0;i<5; i++){
        printf("%d\t",array[i]);
    }
}