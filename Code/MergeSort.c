#include <stdio.h>
#include <stdlib.h>

void merge(int array1[], int array2[], int size1, int size2, int array[]) {
    int a = 0, b = 0, c = 0;

    while (a != size1 && b != size2) {
        if (array1[a] < array2[b]) {
            array[c++] = array1[a++];
        } else {
            array[c++] = array2[b++];
        }
    }
    while (a != size1) {
        array[c++]=array1[a++];
    }
    while (b != size2) {
        array[c++]=array2[b++];
    }
}

void merge_sort(int array[], int size) {
    if (size > 1) {
        int size1 = size/2;
        int size2 = size - size1;
        int *temp_array = calloc(sizeof(int), size);

        for(int i=0;i<size;i++)
            temp_array[i]=array[i];

        merge_sort(temp_array, size1);
        merge_sort(temp_array+size1, size2);
        merge(temp_array, temp_array+size1, size1, size2, array);
    }
    else
        return;
}

int main(){
    int array[5]={9, 6, 4, 7, 1};
    merge_sort(array,5);
    for(int i=0;i<5; i++){
        printf("%d\t",array[i]);
    }
}