#include "avltree.h"

#include <stdio.h>
#include <stdlib.h>

void rotate_left(struct AvlNode **node) {
    struct AvlNode *mid = (*node)->right;
    mid->left = *node;
    *node = mid;
}

void rotate_right(struct AvlNode **node) {
    struct AvlNode *mid = (*node)->left;
    mid->right = *node;
    *node = mid;
}

/// @brief creates a new avl node
/// @param data: The data
/// @param left: The left node
/// @param right: The right node
struct AvlNode *
avl_node(
    int data, 
    struct AvlNode *left, 
    struct AvlNode *right
) {
    struct AvlNode *node = malloc(sizeof(struct AvlNode));
    if (node == NULL) {
        perror("malloc failed while allocating an avl node\n");
        exit(1);
    }
    node->data = data;
    node->balance = 0;
    node->left = left;
    node->right = right;
    return node;
}

AvlTree *
avl_node() {
    AvlTree *tree = malloc(sizeof(AvlTree));
    if (tree == NULL) {
        perror("Malloc failed while allocating an avl tree\n");
        exit(1);
    }
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

AvlTree *
avl_tree_with_data(
    int data
) {
    AvlTree *tree = malloc(sizeof(AvlTree));
    if (tree == NULL) {
        perror("Malloc failed while allocating an avl tree\n");
        exit(1);
    }
    tree->root = avl_node(data, NULL, NULL);
    tree->size = 1;
    return tree;
}

AvlTree *
avl_tree_with_node(
    struct AvlNode *node
) {
    AvlTree *tree = malloc(sizeof(AvlTree));
    if (tree == NULL) {
        perror("Malloc failed while allocating an avl tree\n");
        exit(1);
    }
    tree->root = node;
    tree->size = 1;
    return tree;
}

int
iterate_lookup(
    struct AvlNode *node,
    int data
) {
    if (node->data == data) {
        return 1;
    }
    int res = 0;
    if (node->left == NULL) {
        res = iterate_lookup(node->left, data);
    }
    if (node->right == NULL) {
        res = iterate_lookup(node->right, data);
    }
    return res;
}

int
avl_tree_lookup(
    AvlTree *tree,
    int data
) {
    if (
        tree == NULL
    ) {
        return 0;
    }
    return iterate_lookup(tree->root, data);
}

int iterate_insert(struct AvlNode *node) {

}

int
avl_tree_insert(
    AvlTree *tree,
    struct AvlNode *node
) {
    if (
        tree == NULL
    ) {
        return 0;
    }
}