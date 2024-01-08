#ifndef AVL_TREE_H
#define AVL_TREE_H

struct AvlNode {
    int balance;
    int data;
    struct AvlNode *left;
    struct AvlNode *right;
};

typedef struct {
    struct AvlNode *root;
    unsigned int size;
} AvlTree;

/// @brief Creates a new avl tree
/// @return A pointer to a new avl tree
AvlTree *avl_tree();

/// @brief Creates an avl tree with given data
/// @param data: The data
/// @return The new avl tree
AvlTree *avl_tree_with_data(int data);

/// @brief Creates a new avl tree with a given node
/// @param node: The node
/// @return The avl tree
AvlTree *avl_tree_with_node(struct AvlNode *node);

/// @brief Looks up data in the tree
/// @param tree: The tree
/// @param data: The data
/// @return Return data
int avl_tree_lookup(AvlTree *tree, int data);

/// @brief Inserts a new node into the tree
/// @param tree: The tree
/// @param node: The node
void avl_tree_insert(AvlTree *tree, struct AvlNode *node);

/// @brief Inserts a new node with given data into the tree
/// @param tree: The tree
/// @param data: The data
void avl_tree_insert_data(AvlTree *tree, int data);

/// @brief Deletes a given data from the tree
/// @param tree: The tree
/// @param data: The data
void avl_tree_delete(AvlTree *tree, int data);

/// @brief Frees the avl tree
/// @param tree: The tree to free
void free_avl_tree(AvlTree *tree);

#endif