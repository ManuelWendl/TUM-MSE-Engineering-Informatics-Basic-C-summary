#include <stdlib.h>
#include <stdio.h>
// Pseudo Code
    //void* malloc(size_t size);
    //void* calloc(size_t num, size_t size);
    //free(memory_name);
// Example
    typedef struct{
        char matr_nr[10];
        int semester;
    }student;

    int main(){
        printf("Enter one if you want to insert a student\n");
        int x = getchar();
        if(x=='1'){
            student *new = calloc(sizeof(student),1);
            printf("Please enter the matr_nr.\n");
            char *matr_numb = malloc(10*sizeof(int));
            fflush(stdin);
            scanf("%9s",matr_numb);
            matr_numb[9]=0; // have to initialize determining element manually as malloc doesn't initialize to zero.
            for(int i=0;i<10;i++) {
                new->matr_nr[i] = matr_numb[i];
            }
            free(matr_numb); // Memory of help array can be freed
            printf("Please enter semester.\n");
            fflush(stdin);
            char s = getchar();
            new->semester = s;
            printf("Inserted student: matr_nr: %s semester: %c\n",new->matr_nr,new->semester);
            free(new->matr_nr); // freed after print if you want to keep then don't free!
        }else{
            printf("You didn't want to insert a student\n");
        }
    }