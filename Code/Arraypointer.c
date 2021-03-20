// Example for 1)
    int a[5] = {1,2,3,4,5};
    int *p = 0;
    p = a;
// Example for 2)
    char a[5] = {1,2,3,4,5};
    x = a[2];
    x = *(a+2); // Equal to statement above
// Example for 3)
    void equal(int str[]){
        ...
    }
    void equal(int *str){
        ...
    }