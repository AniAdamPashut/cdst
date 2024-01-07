#ifndef LINKED_LIST
#define LINKED_LIST

/// @brief Simple Node struct
typedef struct Node
{
    void *data;
    struct Node *next;
} Node;


/// @brief Creates a new node
/// @param data: The data of the node 
/// @param next: The next node in the chain
/// @return The new node
Node *node(void *data, Node *next);

/// @brief Frees the whole list
/// @param head: The head of the list to free
void free_node(Node *head);

#endif
