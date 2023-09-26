/*------------------------------------------
Jamie Grasley
Felix Ikokwu
COMP-2412
Assignment 1
--------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

// Define the Queue data structure
struct Queue {
    int* arr; //Make an array to 
    int head; //Stores the head of the queue    
    int tail; //Stores the tail of the queue
    int size; //Stores the size of the queue
};

// Function to initialize the queue
void build(struct Queue **q, unsigned int length) { //Function's definition which takes a queue structure and an unsigned int for the length.
    *q = (struct Queue*)malloc(sizeof(struct Queue)); //Reserves the memory required for the operation
    if (*q == NULL) { //Prevents null pointers memory operations by exiting if detected.
        printf("Memory allocation failed due to null pointer.\n"); //Provides an error message
        exit(1); //Exits with error code 1
    }
    (*q)->arr = (int*)malloc(sizeof(int) * length);
    if ((*q)->arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    (*q)->head = -1; //Initializes the head to be -1
    (*q)->tail = -1; //Initializes the tail to be -1
    (*q)->size = length; //Sets the size to be equal to the length
    printf("Building a queue of length %d\n", length); //Provides the queue length as a terminal response
    printf("Allocated memory for the struct at the address %p\n", *q); //Provides the memory address of the structure as a temrinal response
    printf("Initialize all elements of data to -1\n"); //Provides information on what the elements are initalized to as a terminal response. 
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {//Function definition takes a queue structure
    return (queue->head == -1); //The function is empty if the head is -1
}

// Function to check if the queue is full
int isFull(struct Queue* queue) { //Function definition takes a queue structure
    return ((queue->tail + 1) % queue->size == queue->head); //The function is full if the tail+1%size equals the head of the queue 
}

// Function to enqueue an element
void enqueue(struct Queue* queue, char x) { //Function definition takes a queue structure and a char value.
    if (isFull(queue)) {//Checks if the queue is full
        printf("Attempt to overflow the queue at %p was prevented.\n", (void *) queue);//If full the overflow is prevented at the given address
    } else {
        if (isEmpty(queue)) { //If the queue is empty the head and tail are set.
            queue->head = 0;
            queue->tail = 0;
        } else {
            queue->tail = (queue->tail + 1) % queue->size; //When not empty the queue sets the tail
        }
        queue->arr[queue->tail] = x; //The value x is pushed into the queue at the tail
    
    }
}

// Function to dequeue an element
char dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Attempt to underflow the queue at %p was prevented.\n",  (void *) queue); //If the queue is empty an underflow is prevented at the given address
    } else {
        int x = queue->arr[queue->head]; 
        if (queue->head == queue->tail) { //If the queue becomes empty it fixes the head and tail values
            queue->head = -1;
            queue->tail = -1;
        } else {
            queue->head = (queue->head + 1) % queue->size; //If not empty it fixes the order of queue
        }
        return x; //Returns the dequeued value
    }
}

int main(int argc, const char * argv[]) {
    struct Queue *qptr = NULL; //Points the queue to NULL
  
    printf("\n\nBegin Test Case 1\n\n");
  
    build(&qptr, 5); //Builds a queue of size 5

    // ====== Begin Test Case 1
    enqueue(qptr, 1); //Queues value 1
    enqueue(qptr, 2);
    enqueue(qptr, 3);
    enqueue(qptr, 4);
    enqueue(qptr, 5);
    enqueue(qptr, 6); //Attempts to queue value 6
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr)); //Attempts to dequeue a sixth value
    // ====== End Test Case 1

    // Free memory allocated for the queue
    if (qptr->arr) free(qptr->arr); 
    if (qptr) free(qptr);
  printf("\n\nBegin Test Case 2\n\n");
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
   printf("\n\nBegin Test Case 3\n\n");
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

    printf("\n\nBegin Test Case 4\n\n");
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
  printf("\n\nBegin Test Case 5\n\n");
  build(&qptr, 10);
  // ====== Begin Test Case 5
    enqueue(qptr, -8);
    enqueue(qptr, 77);
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    enqueue(qptr, 57);
    enqueue(qptr, 73);
    printf("Dequeue() %d \n", dequeue(qptr));
    // ====== End Test Case 5
    printf("\n");
    // Free memory allocated for the queue
    if (qptr->arr) free(qptr->arr);
    if (qptr) free(qptr);
  printf("\n\nBegin Test Case 5\n\n");
    return 0;
}