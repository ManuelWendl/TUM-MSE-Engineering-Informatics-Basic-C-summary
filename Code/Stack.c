#include <stdlib.h>
#include <stdio.h>

struct Stack{
    struct Element *top;
};

struct Element{
    int data;
    struct Element *prev;
};

struct Stack *init_stack(){
    struct Stack *newstack = calloc(sizeof(newstack),1);
    newstack->top = NULL;
    return newstack;
}

void push(struct Stack *stack, int data){
    struct Element *element = calloc(sizeof(element),1);
    element->data = data;
    element->prev=stack->top;
    stack->top=element;
}

void pop(struct Stack *stack){
    if(stack->top!=NULL){
        struct Element *temp = stack->top->prev;
        printf("Popping Element with data: %d \n", stack->top->data);
        free(stack->top);
        stack->top = temp;
    }
}

void top(struct Stack *stack){
    if(stack->top!=NULL){
        printf("Top Element has data: %d \n", stack->top->data);
    }else{
         printf("Stack empty. \n");
    }
}

int main(){
    struct Stack *stack = init_stack();
    push(stack,5);
    push(stack,10);
    top(stack);
    pop(stack);
    top(stack);
    pop(stack);
    top(stack);
}