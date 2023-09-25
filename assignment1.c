/*------------------------------------------
Jamie Grasley
Felix
COMP-2412
Assignment 1
--------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

// Define the Queue data structure
struct Queue {
    int* arr;
    int head;
    int tail;
    int size;
};

// Function to initialize the queue
void build(struct Queue **q, unsigned int length) {
    *q = (struct Queue*)malloc(sizeof(struct Queue));
    if (*q == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    (*q)->arr = (int*)malloc(sizeof(int) * length);
    if ((*q)->arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    (*q)->head = -1;
    (*q)->tail = -1;
    (*q)->size = length;
    printf("Building a queue of length %d\n", length);
    printf("Allocated memory for the struct at the address %p\n", *q);
    printf("Initialize all element of data to -1\n");
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->head == -1);
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return ((queue->tail + 1) % queue->size == queue->head);
}

// Function to enqueue an element
void enqueue(struct Queue* queue, char x) {
    if (isFull(queue)) {
        printf("Attemp to overflow the queue at %p was prevented.\n", (void *) queue);
    } else {
        if (isEmpty(queue)) {
            queue->head = 0;
            queue->tail = 0;
        } else {
            queue->tail = (queue->tail + 1) % queue->size;
        }
        queue->arr[queue->tail] = x;
    
    }
}

// Function to dequeue an element
char dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Attemp to underflow the queue at %p was prevented.\n",  (void *) queue);
    } else {
        int x = queue->arr[queue->head];
        if (queue->head == queue->tail) {
            queue->head = -1;
            queue->tail = -1;
        } else {
            queue->head = (queue->head + 1) % queue->size;
        }
        return x;
    }
}

int main(int argc, const char * argv[]) {
    struct Queue *qptr = NULL;

    build(&qptr, 5);

    // ====== Begin Test Case 1
    enqueue(qptr, 1);
    enqueue(qptr, 2);
    enqueue(qptr, 3);
    enqueue(qptr, 4);
    enqueue(qptr, 5);
    enqueue(qptr, 6);
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    // ====== End Test Case 1

    // Free memory allocated for the queue
    if (qptr->arr) free(qptr->arr);
    if (qptr) free(qptr);
   build(&qptr, 5);
  // ====== Begin Test Case 2
    enqueue(qptr, 1);
    printf("Dequeue() %d \n", dequeue(qptr));
    enqueue(qptr, 2);
    enqueue(qptr, 3);
    printf("Dequeue() %d \n", dequeue(qptr));
    enqueue(qptr, 4);
    enqueue(qptr, 5);
    printf("Dequeue() %d \n", dequeue(qptr));
    enqueue(qptr, 6);
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    enqueue(qptr, 5);
    enqueue(qptr, 5);
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    enqueue(qptr, 5);
    printf("Dequeue() %d \n", dequeue(qptr));
    enqueue(qptr, 5);
    // ====== End Test Case 2

    // Free memory allocated for the queue
    if (qptr->arr) free(qptr->arr);
    if (qptr) free(qptr);
    build(&qptr, 9);
  // ====== Begin Test Case 3
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    enqueue(qptr, 1);
    printf("Dequeue() %d \n", dequeue(qptr));
    enqueue(qptr, 2);
    enqueue(qptr, 3);
    printf("Dequeue() %d \n", dequeue(qptr));
    enqueue(qptr, 4);
    enqueue(qptr, 5);
    printf("Dequeue() %d \n", dequeue(qptr));
    enqueue(qptr, 6);
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    enqueue(qptr, 5);
    printf("Dequeue() %d \n", dequeue(qptr));
    enqueue(qptr, 5);
    printf("Dequeue() %d \n", dequeue(qptr));
    // ====== End Test Case 3

    // Free memory allocated for the queue
    if (qptr->arr) free(qptr->arr);
    if (qptr) free(qptr);
  
    build(&qptr, 5);
  // ====== Begin Test Case 4
    enqueue(qptr, 5);
    enqueue(qptr, 70);
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    // ====== End Test Case 4
// Free memory allocated for the queue
    if (qptr->arr) free(qptr->arr);
    if (qptr) free(qptr);
  
  build(&qptr, 10);
  // ====== Begin Test Case 5
    enqueue(qptr, 8);
    enqueue(qptr, 77);
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    enqueue(qptr, 57);
    enqueue(qptr, 73);
    printf("Dequeue() %d \n", dequeue(qptr));
    // ====== End Test Case 5
    printf("\n");
    return 0;
}