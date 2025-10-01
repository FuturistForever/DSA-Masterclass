#include <stdio.h>
#include <stdlib.h>

// Define the maximum size for the underlying queues
#define MAX_SIZE 100

// --- Queue Implementation (Helper structure) ---

typedef struct {
    int items[MAX_SIZE];
    int front; // Index of the front element
    int rear;  // Index where the next element will be added
    int size;  // Current number of elements
} Queue;

// Initializes a queue
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Checks if the queue is empty
int isEmpty(Queue* q) {
    return q->size == 0;
}

// Checks if the queue is full
int isFull(Queue* q) {
    return q->size == MAX_SIZE;
}

// Adds an element to the rear of the queue (O(1))
void enqueue(Queue* q, int x) {
    if (isFull(q)) {
        printf("Queue Full (Cannot enqueue %d)\n", x);
        return;
    }
    // Handle circular array implementation: rear wraps around
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = x;
    q->size++;
}

// Removes and returns the element from the front of the queue (O(1))
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Empty\n");
        return -1; // Error value
    }
    int item = q->items[q->front];
    // Handle circular array implementation: front wraps around
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return item;
}

// --- Stack Implementation using Two Queues ---

typedef struct {
    Queue q1; // Main queue (holds stack elements)
    Queue q2; // Helper queue (used during pop/top operations)
} Stack;

// Initializes the stack by initializing its two queues
void initStack(Stack* s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

// PUSH operation (O(1) complexity)
// Simply adds the new element to the main queue (q1).
void stackPush(Stack* s, int x) {
    if (isFull(&s->q1)) {
        printf("Stack Overflow\n");
        return;
    }
    enqueue(&s->q1, x);
    printf("Pushed: %d\n", x);
}

// POP operation (O(n) complexity)
// To simulate LIFO, move n-1 elements from q1 to q2, 
// then dequeue the last remaining element (the top of the stack) from q1.
int stackPop(Stack* s) {
    if (isEmpty(&s->q1)) {
        printf("Stack is empty\n");
        return -1;
    }

    // 1. Move n-1 elements from q1 to q2
    // We stop when only one element (the top of the stack) remains in q1.
    while (s->q1.size > 1) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    // 2. Dequeue the last element from q1 (this is the LIFO element)
    int popped_item = dequeue(&s->q1);

    // 3. Swap the names/roles of q1 and q2. 
    // The helper queue (q2) now becomes the main queue (q1) for future operations.
    // This is done by swapping the entire Queue structures.
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
    
    // Note: After the swap, q2 is now empty, ready to be the helper again.

    return popped_item;
}

// Returns the top element without removing it (O(n) complexity)
int stackTop(Stack* s) {
    if (isEmpty(&s->q1)) {
        printf("Stack is empty\n");
        return -1;
    }
    
    // Move n-1 elements from q1 to q2
    while (s->q1.size > 1) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    // Get the last element (top)
    int top_item = dequeue(&s->q1);

    // Enqueue the top element back into q2 (since we don't want to lose it)
    enqueue(&s->q2, top_item);

    // Swap q1 and q2 to restore the main queue
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;

    return top_item;
}

// Checks if the stack is empty
int stackIsEmpty(Stack* s) {
    return isEmpty(&s->q1);
}

// --- Main function for demonstration ---
int main() {
    Stack myStack;
    initStack(&myStack);

    // Push 10
    stackPush(&myStack, 10); // q1: [10], q2: []
    // Push 20
    stackPush(&myStack, 20); // q1: [10, 20], q2: []
    // Push 30
    stackPush(&myStack, 30); // q1: [10, 20, 30], q2: []

    // Get Top (Should be 30)
    printf("Top element: %d\n", stackTop(&myStack)); // O(n)

    // Pop 30
    // q1: [10, 20] -> move 10, 20 to q2. q1: [30], q2: [10, 20]
    // Dequeue 30 from q1.
    // Swap: q1: [10, 20], q2: [30] (but q2 is reset in init, so conceptually empty)
    printf("Popped: %d\n", stackPop(&myStack)); // O(n)

    // Push 40
    stackPush(&myStack, 40); // q1: [10, 20, 40], q2: []

    // Pop 40
    printf("Popped: %d\n", stackPop(&myStack)); // O(n)

    // Pop 20
    printf("Popped: %d\n", stackPop(&myStack)); // O(n)

    // Pop 10
    printf("Popped: %d\n", stackPop(&myStack)); // O(n)

    // Pop from empty stack
    printf("Popped: %d\n", stackPop(&myStack)); // Stack is empty

    return 0;
}
