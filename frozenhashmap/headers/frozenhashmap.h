#ifndef FROZEN_HASHMAP_H
#define FROZEN_HASHMAP_H

#include "linkedlist.h"
#include "hashutils.h"

/// @brief The FrozenHashMap struct
typedef struct {
    struct HashBucket *buckets;
    unsigned int capacity;
} FrozenHashMap;

/// @brief Creates a new hashmap
/// @param capacity: The capacity of the hashmap
/// @return The new hashmap
FrozenHashMap *frozen_hash_map(unsigned int);

/// @brief Looks up a key in the map
/// @param fhm: The FrozenHashMap
/// @param key: The key to lookup
/// @return A pointer to the `HashEntry`
HashEntry *fh_lookup(FrozenHashMap *, char *);

/// @brief Inserts an item into the map
/// @param fhm: The FrozenHashMap
/// @param key: The key to insert
/// @param item: The item to insert
void fh_insert(FrozenHashMap *, char *, void *);

/// @brief Deletes an item from the map
/// @param fhm: The FrozenHashMap
/// @param key: The key to delete
void fh_delete(FrozenHashMap *, char *);

/// @brief Frees a FrozenHashMap
/// @param fhm: The FrozenHashMap to free
void free_fhm(FrozenHashMap *);

#endif