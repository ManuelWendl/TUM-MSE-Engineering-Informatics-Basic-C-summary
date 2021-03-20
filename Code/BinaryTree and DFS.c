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

void DFS_inorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    DFS_inorder(root->left_child);
    printf("%d \t", root->data);
    DFS_inorder(root->right_child);
}

void DFS_preorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d \t", root->data);
    DFS_preorder(root->left_child);
    DFS_preorder(root->right_child);
}

void DFS_postorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    DFS_postorder(root->left_child);
    DFS_postorder(root->right_child);
    printf("%d \t", root->data);
}

int Binary_search(struct Node *root, int search) {
    if (root == NULL) {
        return 0;
    } else if (root->data == search)
        return 1;
    else if (search < root->data)
        return Binary_search(root->left_child, search);
    else
        return Binary_search(root->right_child, search);
}

int insert_search(struct Node *root, int search) {
    if (search < root->data) {
        if (root->left_child)
            return insert_search(root->left_child, search);
        else {
            struct Node *new_child = init_node(search);
            root->left_child = new_child;
            return 0;
        }
    }
    else if (search > root->data) {
        if (root->right_child)
            return insert_search(root->right_child, search);
        else {
            struct Node *new_child = init_node(search);
            root->right_child = new_child;
            return 0;
        }
    }
    else
        return 1;
}

int main() {
    struct Tree *tree = init_tree(5);
    add_sorted_node(tree->root, 10);
    add_sorted_node(tree->root, 0);
    add_sorted_node(tree->root, 8);
    add_sorted_node(tree->root, 12);
    add_sorted_node(tree->root, 7);
    add_sorted_node(tree->root, 9);
    printf("Is element in tree: %d \n", insert_search(tree->root, 13));
    printf("DFS inorder: \t");
    DFS_inorder(tree->root);
    printf("\n");
    printf("DFS preorder: \t");
    DFS_preorder(tree->root);
    printf("\n");
    printf("DFS postorder: \t");
    DFS_postorder(tree->root);
    printf("\n");
}



