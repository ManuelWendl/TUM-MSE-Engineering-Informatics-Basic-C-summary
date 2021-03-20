#include <stdlib.h>
#include <stdio.h>

struct Tree {
    struct Node *root;
};

struct Node {
    int data;
    struct Node *left_child;
    struct Node *right_child;
};

struct Node *init_node(int data) {
    struct Node *new = calloc(sizeof(struct Node), 1);
    new->data = data;
    return new;
}

struct Tree *init_tree(int data) {
    struct Tree *tree = calloc(sizeof(struct Tree), 1);
    tree->root = init_node(data);
    return tree;
}

void add_sorted_node(struct Node *current, int data) {
    if (data < current->data) {
        if (current->left_child == NULL) {
            current->left_child = init_node(data);
        } else {
            add_sorted_node(current->left_child, data);
        }
    } else if (data > current->data) {
        if (current->right_child == NULL) {
            current->right_child = init_node(data);
        } else {
            add_sorted_node(current->right_child, data);
        }
    }
}

// Implementation of DFS as Stack
struct Stack{
    struct Element *top;
};

struct Element{
    struct Node *node;
    struct Element *prev;
};

void push(struct Stack *stack, struct Node *node){
    struct Element *element = calloc(sizeof(element),1);
    element->node = node;
    element->prev=stack->top;
    stack->top=element;
}

void pop(struct Stack *stack){
    if(stack->top!=NULL){
        struct Element *temp = stack->top->prev;
        printf("Popping Element with data: %d \n", stack->top->node->data);
        free(stack->top);
        stack->top = temp;
    }
}

void DFSalg(struct Node *current, struct Stack *stack){
    if(current->left_child!=NULL) {
        push(stack, current->left_child);
        DFSalg(current->left_child,stack);
    }
    pop(stack);
    if(current->right_child) {
        push(stack, current->right_child);
        DFSalg(current->right_child, stack);
    }
}

void DFSframe(struct Tree *tree){
    struct Stack *stack = calloc(sizeof(stack),1);
    push(stack,tree->root);
    DFSalg(tree->root, stack);
}

int main() {
    struct Tree *tree = init_tree(5);
    add_sorted_node(tree->root, 10);
    add_sorted_node(tree->root, 0);
    add_sorted_node(tree->root, 8);
    add_sorted_node(tree->root, 12);
    add_sorted_node(tree->root, 7);
    add_sorted_node(tree->root, 9);
    DFSframe(tree);
}