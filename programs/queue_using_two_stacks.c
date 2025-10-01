#include <stdio.h>
#include <stdlib.h> // For exit()

#define MAX_SIZE 100

// --- Stack Implementation (Necessary Helper Functions) ---

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Function to initialize a stack
void initStack(Stack* s) {
    s->top = -1;
}

// Function to check if stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to push an item onto the stack
void push(Stack* s, int x) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = x;
}

// Function to pop an item from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1; // Error value
    }
    return s->items[s->top--];
}

// --- Queue Implementation using Two Stacks ---

typedef struct {
    Stack s1; // Enqueuing stack
    Stack s2; // Dequeuing stack
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    initStack(&q->s1);
    initStack(&q->s2);
}

// ENQUEUE operation (O(1) complexity)
void enqueue(Queue* q, int x) {
    push(&q->s1, x);
    printf("Enqueued: %d\n", x);
}

// DEQUEUE operation (Amortized O(1) complexity)
int dequeue(Queue* q) {
    // 1. If s2 is not empty, dequeue directly
    if (!isEmpty(&q->s2)) {
        return pop(&q->s2);
    }
    
    // 2. If both stacks are empty, queue is empty
    if (isEmpty(&q->s1)) {
        printf("Queue is empty\n");
        return -1; // Error value
    }
    
    // 3. Move all elements from s1 to s2
    while (!isEmpty(&q->s1)) {
        push(&q->s2, pop(&q->s1));
    }
    
    // 4. Dequeue from s2
    return pop(&q->s2);
}

// Example usage
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Dequeued: %d\n", dequeue(&q)); // Output: 10
    printf("Dequeued: %d\n", dequeue(&q)); // Output: 20
    
    enqueue(&q, 40);
    
    printf("Dequeued: %d\n", dequeue(&q)); // Output: 30
    printf("Dequeued: %d\n", dequeue(&q)); // Output: 40
    printf("Dequeued: %d\n", dequeue(&q)); // Output: Queue is empty, -1

    return 0;
}
