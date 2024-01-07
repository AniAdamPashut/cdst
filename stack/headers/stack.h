#ifndef STACK_H
#define STACK_H

#include "linkedlist.h"

/// @brief The stack structure
typedef struct {
    Node *head;
    int size;
} Stack;

/// @brief Function that creates a new stack
/// @return A new Stack
Stack *stack();

/// @brief Pushes an item on top of the stack
/// @param stack: The stack to push onto
/// @param item: The item to push
void push(Stack *, void *);

/// @brief Pops an item from the struct
/// @param stack: The stack to pop from
/// @return The popped item
void *pop(Stack *);

/// @brief Returns a peek from the stack
/// @param stack: The stack to peek
/// @return The peeked item
void *top(Stack *);

/// @brief Frees the whole stack
/// @param stack: The stack to free
void free_stack(Stack *);

#endif