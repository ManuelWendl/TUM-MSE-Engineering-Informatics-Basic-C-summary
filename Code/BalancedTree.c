#include <stdlib.h>
#include <stdio.h>

struct Tree {
    struct Node *root;
};

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
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
        if (current->left == NULL) {
            current->left = init_node(data);
        } else {
            add_sorted_node(current->left, data);
        }
    } else if (data > current->data) {
        if (current->right == NULL) {
            current->right = init_node(data);
        } else {
            add_sorted_node(current->right, data);
        }
    }
}

void DFS_inorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    DFS_inorder(root->left);
    printf("%d \t", root->data);
    DFS_inorder(root->right);
}

/* Check for Balancing of Tree */
int balanced_Tree(struct Node *root){
    if(root == 0)
        return 0;
    int leftSubtree = balanced_Tree(root->left);
    if(leftSubtree == -1)
        return -1;
    int rightSubtree = balanced_Tree(root->right);
    if(rightSubtree == -1)
        return -1;
    if(abs(leftSubtree-rightSubtree)>1)
        return -1;

    if(leftSubtree>rightSubtree) {
        int max = leftSubtree;
        return max+1;
    }
    else {
        int max = rightSubtree;
        return max+1;
    }
}

int main(){
    struct Tree *tree = init_tree(5);
    add_sorted_node(tree->root, 10);
    add_sorted_node(tree->root, 0);
    add_sorted_node(tree->root, 8);
    add_sorted_node(tree->root, 12);
    DFS_inorder(tree->root);
    printf("\nBalanced tree length: %d \n",balanced_Tree(tree->root));
}