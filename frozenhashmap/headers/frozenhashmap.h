#ifndef FROZEN_HASHMAP_H
#define FROZEN_HASHMAP_H

#include "linkedlist.h"
#include "hashutils.h"

typedef struct {
    struct HashBucket *buckets;
    unsigned int capacity;
} FrozenHashMap;

FrozenHashMap *frozen_hash_map(unsigned int);

HashEntry *fh_lookup(FrozenHashMap *, char *);

void fh_insert(FrozenHashMap *, char *, void *);

void fh_delete(FrozenHashMap *, char *);

void free_fhm(FrozenHashMap *);

#endif