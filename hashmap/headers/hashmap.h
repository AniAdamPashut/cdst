#ifndef HASHMAP_H
#define HASHMAP_H

#include "hashutils.h"

/// @brief The HashMap struct
typedef struct {
    unsigned int capacity;
    unsigned int size;
    HashEntry *entries;
    int *is_taken;
} HashMap;

/// @brief Creates an empty HashMap
/// @return The HashMap
HashMap *hash_map();

/// @brief Creates a HashMap with a starter capacity
/// @param capacity: The capacity
/// @return The new HashMap
HashMap *hash_map_with_capacity(unsigned int);

/// @brief Lookup in the HashMap for the key. NULL on failure
/// @param hm: The HashMap
/// @param key: The key
/// @return A pointer to the HashEntry
HashEntry *hm_lookup(HashMap *, char *);

/// @brief Insert a new key, value pair into the HashMap
/// @param hm: The HashMap
/// @param key: The key
/// @param value: The value
void hm_insert(HashMap *, char *, void *);

/// @brief Deletes a key, value pair from the HashMap
/// @param hm: The HashMap
/// @param key: The key
/// @return The HashEntry of the deleted values
HashEntry *hm_delete(HashMap *, char *);

/// @brief Frees the HashMap
/// @param hm: The HashMap to free
void free_hashmap(HashMap *);

#endif