# COMP-2412-A1
Assignment 1 for COMP-2412 at Lakehead University

# Problem statement
Assignment 1 Queues

2412FB-Data Structures 
Department of Computer Science
Fall 2023
	This assignment should be completed in groups of two. Both students will receive the same grade.
	You must submit your solution through D2L. Don’t email your submission.
	Please refrain from uploading zipped files.
	Do not upload executables.
	The due date is September 29, 2023, at 5:00 PM (Toronto time).

Write a C program to implement a queue of at most n-1 elements using an array of size n.

	At the beginning of your code (outside all subprograms), declare a datatype named `struct Queue`. It must be designed according to the pseudo codes (refer to Figure 2) and the provided main function. (10 points)

	Define the subprograms to implement the build, enqueue, and dequeue operations. The meaning of enqueue and dequeue is explained in the pseudocodes in Figure 2. The pseudocodes do not include error checking for underflow and overflow. You are required to extend and implement them to prevent underflow and overflow of the queue. (75 points)

	Additionally, your code must check for any other potential errors, such as accessing null pointers. Also, add a few comments to your code to explain the behavior of the main and subprograms. Ensure that your build, enqueue, and dequeue operations print informative messages as demonstrated in Figure 3. (5 points)

	Ensure you test your code with varying sequences of enqueue and dequeue operations. Including five test cases should be sufficient. Your report should briefly explain your test cases and results. Please limit the explanations to few lines and embed screenshots of your program output. (5 points for test cases and 5 points for the clarity and coherence of the report)

| Api | Return Value |
| :-: | :-:|
| `void build(struct Queue **q, unsigned int length)`|	Builds the queue of the specified ‘length’. Initializes the queue elements. The memory address of the created queue is stored in q.|
| `void enqueue(struct Queue *q, char x)`|	No return value. Side effect; x stored at the tail of Q. The tail is incremented by one.|
| `char dequeue(struct Queue *q)`|	Returns the value stored at the head. Head incremented. Returns error code, if some encountered.|
 
Figure 1 A queue implemented using an array Q[1..12].

<img width="367" alt="image" src="https://github.com/JamieHour/COMP-2412-A1/assets/16744724/8215a46a-4893-49ac-96f0-300e49184da8">

Figure 1 shows the effects of the enqueue and dequeue operations. Queue elements appear only in the lightly shaded positions. Figure 1(a) shows a case where the queue has 5 elements, in locations Q[7..11]. Figure 1(b) shows the configuration of the queue after the calls ENQUEUE(Q,17), ENQUEUE(Q, 3), and ENQUEUE(Q, 5). Figure 1(c) shows the configuration of the queue after the call DEQUEUE(Q) which returns the key value 15 formerly at the head of the queue. The new head has the value 6 (stored at the position 8).
The following pseudo codes describe the meaning of the enqueue and dequeue operations.  
 
Figure 2 Pseudocodes for enqueue and dequeue subprograms

<img width="306" alt="image" src="https://github.com/JamieHour/COMP-2412-A1/assets/16744724/159148c7-e3a6-48ad-81de-53c6c8a227c2">

Test
Your code will be tested using the following main function:

    int main(int argc, const char * argv[]) {
    struct Queue *qptr = NULL;

    build(&qptr, 5);
    // ====== Beginn Test Case 1
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
    // ====== End Test Case 1
    
    // free anything that was created with malloc!
    if (qptr->data) free(qptr->data);
    if(qptr) free(qptr);
    printf("\n");
    return 0;
    }

Output:
 
Figure 3 Output of an example program with one test case.

<img width="527" alt="image" src="https://github.com/JamieHour/COMP-2412-A1/assets/16744724/b20b7036-ee33-4c20-866a-10e2c0c3400b">

Your submission (the solution)


Your submission should consist of two files: a PDF report and a C file containing the code.
We will only evaluate a submission if we can successfully compile and run the submitted C-file. Otherwise, you won't receive any marks for this assignment.

If your implementation lacks proper error checking (e.g., for illegal pointer operations such as attempts to dereference null pointers) or fails to prevent an underflow or overflow, or does not correctly implement the pseudo codes illustrated in Figure 2, then points will be deducted.

Should you require further clarification regarding the assignment, please ask questions during the lab hours, or feel free to contact me via Zoom during my office hours. You can find my office hours in the syllabus. Please check the course page for the most updated version of the syllabus.

