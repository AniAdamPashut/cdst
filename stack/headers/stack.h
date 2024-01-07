#ifndef STACK_H
#define STACK_H

#include "linkedlist.h"

typedef struct {
    Node *head;
    int size;
} Stack;

Stack *stack();

void push(Stack *, void *item);

void *pop(Stack *);

void *top(Stack *);

void free_stack(Stack *);

#endif