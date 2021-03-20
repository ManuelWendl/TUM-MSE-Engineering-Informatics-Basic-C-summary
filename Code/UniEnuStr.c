#include <stdio.h>

struct variable{
    enum type{
        INT, //-> 1
        CHAR, //-> 2
        FLOAT //-> 3
    }t;
    union value{
        int a;
        char b;
        float c;
    }v;
};

void different_type_printer(struct variable x){
    switch(x.t){
        case INT:
            printf("int = %d\n",x.v.a);
            break;
        case CHAR:
            printf("char = %c\n",x.v.b);
            break;
        case FLOAT:
            printf("float = %f\n",x.v.c);
            break;
    }
}

int main(){
    struct variable var1;
    var1.v.a = 123;
    var1.t = INT;
    different_type_printer(var1);

    var1.v.b = 'a';
    var1.t = CHAR;
    different_type_printer(var1);

    var1.v.c = 123.456;
    var1.t = FLOAT;
    different_type_printer(var1);
}