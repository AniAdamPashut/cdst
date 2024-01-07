#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

Node *node(void *data, Node *next)
{
    Node *node = malloc(sizeof(Node));
    if (node == NULL)
    {
        fprintf(stderr, "error with malloc new node");
        exit(1);
    }
    node->data = data;
    node->next = next;
    return node;
}

void free_node(Node *head)
{
    while (head != NULL)
    {
        free(head->data);
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}
