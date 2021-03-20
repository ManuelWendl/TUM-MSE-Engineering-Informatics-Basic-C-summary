#include <stdio.h>

int Binary_Search(int search, int array[], int size){
    if(size !=0){
        int middle = size/2;
        if(array[middle]==search)
            return 1;
        else if(array[middle]>search)
            return Binary_Search(search,array,middle);
        else if(array[middle]<search)
            return Binary_Search(search,array+middle+1,size-middle-1);
        else
            return 0;
    }else
        return 0;
}

int main(){
    int array[10]={1, 2, 5, 12, 16, 18, 20, 21, 28, 30};
    for(int i=0;i<10;i++){
        printf("%d\t",array[i]);
    }
    printf("\n");
    printf("%d",Binary_Search(18,array,10));
}