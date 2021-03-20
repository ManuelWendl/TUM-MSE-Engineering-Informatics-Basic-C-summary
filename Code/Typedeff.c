#include <stdio.h>
#include <stdlib.h>
// Pseudo Code
    typedef type newname;
    int func{
        ...
        newname x = value;
        ...
    };
// Example
    typedef unsigned int uint;

    typedef struct{     // typedeff of a struct
        uint Matr_numb;
        uint Semester;
    } student;

    int main(){
        student s;
        s.Matr_numb = 14561;
        s.Semester = 1;
    };