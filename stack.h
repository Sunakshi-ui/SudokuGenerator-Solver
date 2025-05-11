#ifndef STACK_H
#define STACK_H

#define MAX 100

typedef struct Stack {
    int top;
    int items[MAX];
} Stack;

void initStack(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
void startTimer(int time);

#endif

