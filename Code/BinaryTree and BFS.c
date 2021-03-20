#include <stdio.h>
#include <stdlib.h>

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

/* Implementation of BFS with Queue
 * Pseudo Code:
 * Enqueue root node
 * Dequeue the head and add all children of dequeued element to the queue
 * Repeat this until the queue is empty.
*/

struct Queue {
    struct Element *head;
    struct Element *tail;
};

struct Element {
    struct Node *node;
    struct Element *next;
};

struct Queue *init_queue() {
    struct Queue *queue = calloc(sizeof(queue), 1);
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void enqueue(struct Queue *queue, struct Node *data) {
    struct Element *element = calloc(sizeof(element), 1);
    element->node = data;

    if (queue->head == NULL) {
        queue->head = element;
        queue->tail = element;
    } else {
        queue->tail->next = element;
        queue->tail = element;
    }
}

void dequeue(struct Queue *queue) {
    if (queue->head != NULL) {
        struct Element *temp = queue->head;
        free(queue->head);
        queue->head = queue->head->next;
        printf("%d \t", temp->node->data);
    }
}

void BFS(struct Node *node, struct Queue *queue) {
    dequeue(queue);
    if (node->left_child != 0)
        enqueue(queue, node->left_child);
    if (node->right_child != 0)
        enqueue(queue, node->right_child);
    if (queue->head != 0)
        BFS(queue->head->node, queue);
}

void fullBFS(struct Node *node) {
    struct Queue *queue = init_queue();
    struct Element *element = calloc(sizeof(element), 1);
    element->node = node;
    queue->head = element;
    BFS(node, queue);
}

int main() {
    struct Tree *tree = init_tree(5);
    add_sorted_node(tree->root, 10);
    add_sorted_node(tree->root, 0);
    add_sorted_node(tree->root, 8);
    add_sorted_node(tree->root, 12);
    add_sorted_node(tree->root, 7);
    add_sorted_node(tree->root, 9);
    fullBFS(tree->root);
}

