#include <stdio.h>
#include <stdlib.h>

struct Queue{
    struct Element *head;
    struct Element *tail;
};

struct Element{
    int data;
    struct Element *next;
};

struct Queue *init_queue(){
    struct Queue *queue = calloc(sizeof(queue),1);
    queue->head=NULL;
    queue->tail=NULL;
    return queue;
}

void enqueue(struct Queue *queue, int data){
    struct Element *element = calloc(sizeof(element),1);
    element->data=data;

    if(queue->head==NULL){
        queue->head=element;
        queue->tail=element;
    }else{
        queue->tail->next = element;
        queue->tail = element;
    }
}

void dequeue(struct Queue *queue){
    if(queue->head!=NULL){
        struct Element *temp = queue->head;
        free(queue->head);
        queue->head = queue->head->next;
        printf("Dequeuing Element with data: %d \n", temp->data);
    }else{
        printf("Queue empty. \n");
    }
}

void printqueue(struct Queue *queue){
    struct Element *current = queue->head;
    if(current==0){
        printf("Queue empty. \n");
    }else {
        while (current != NULL) {
            printf("Element with data: %d \t", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main(){
    struct Queue *queue = init_queue();
    enqueue(queue,5);
    enqueue(queue, 10);
    enqueue(queue,15);
    printqueue(queue);
    dequeue(queue);
    printqueue(queue);
    dequeue(queue);
    dequeue(queue);
    printqueue(queue);
}