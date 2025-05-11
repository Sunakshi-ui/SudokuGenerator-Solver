#include "stack.h"
#include <stdio.h>
#include <unistd.h> // For sleep()

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow.\n");
        return;
    }
    s->items[++(s->top)] = value;
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow.\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// Timer function using the stack
void startTimer(int seconds) {
    Stack timerStack;
    initStack(&timerStack);

    // Push each second onto the stack
    for (int i = seconds; i > 0; i--) {
        push(&timerStack, i);
    }

    // Pop and display each second to simulate countdown
    printf("Time remaining: ");
    while (!isEmpty(&timerStack)) {
        int currentSecond = pop(&timerStack);
        printf("\rTime remaining: %d secs...", seconds - currentSecond);
        fflush(stdout); // Flush the output buffer to ensure immediate updating of the display
        
        sleep(1); // Wait for 1 second
    }

    printf("\nTimer finished!\n");
}

