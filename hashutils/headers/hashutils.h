#ifndef HASH_UTILITIES_H
#define HASH_UTILITIES_H

/// @brief A simple HashEntry struct
typedef struct {
    char *key;
    void *item;
} HashEntry;

/// @brief A simple hash functions using sum product
/// @param key: string
/// @return The hash
unsigned int hash(char *);

#endif