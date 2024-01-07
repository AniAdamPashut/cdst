#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

Stack *stack() {
    Stack *stk = malloc(sizeof(Stack));
    if (stk == NULL) {
        perror("Mallocating error while creating a stack, womp womp\n");
        exit(1);
    }
    stk->size = 0;
    stk->head = NULL;
    return stk;
}

void push(Stack *stk, void *item) {
    stk->head = node(item, stk->head);
    stk->size++;
}

void *pop(Stack *stk) {
    Node *head = stk->head;
    stk->head = stk->head->next;
    void *item = head->data;
    head->next = NULL;
    head->data = NULL;
    free(head);
    stk->size--;
    return item;
}

void *top(Stack *stk) {
    return stk->head->data;
}

void free_stack(Stack *stk) {
    while (stk->size > 0) {
        free(pop(stk));
    }
    free(stk);
}