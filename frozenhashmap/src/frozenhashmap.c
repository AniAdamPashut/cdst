#include "frozenhashmap.h"
#include "hashutils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HashBucket {
    Node *head;
    unsigned int size;
};


FrozenHashMap *frozen_hash_map(unsigned int capacity) {
    FrozenHashMap *hm = malloc(sizeof(FrozenHashMap));
    hm->buckets = malloc(sizeof(struct HashBucket) * capacity);
    if (hm == NULL) {
        perror("malloc failed while creating a frozen hashmap");
        exit(1);
    }
    hm->capacity = capacity;
    for (int i = 0; i < capacity; i++) {
        struct HashBucket *bucket = hm->buckets + i;
        bucket->head = NULL;
        bucket->size = 0;
    }

    return hm;
}

HashEntry *fh_lookup(FrozenHashMap *fhm, char *key) {
    unsigned int hash_of_key = hash(key);
    unsigned int index = hash_of_key % fhm->capacity;
    struct HashBucket *bucket = fhm->buckets + index;
    if (bucket->size <= 0) {
        return NULL;
    } 
    Node *runner = bucket->head;
    while (runner != NULL) {
        HashEntry *data = (HashEntry *)runner->data;
        if (strcmp(data->key, key) == 0) {
            return data;
        }
    }
    return NULL;
}

void fh_insert(
    FrozenHashMap *fhm, 
    char *key, 
    void *item) {
        HashEntry *he = malloc(sizeof(HashEntry));
        he->key = strdup(key);
        he->item = item;
        unsigned int hash_of_key = hash(key);
        unsigned int index = hash_of_key % fhm->capacity;
        struct HashBucket *bucket = fhm->buckets + index;
        bucket->head = node(he, bucket->head);
        bucket->size += 1;
    }

void fh_delete(
    FrozenHashMap *fhm,
    char *key) {
        unsigned int hash_of_key = hash(key);
        unsigned int index = hash_of_key % fhm->capacity;
        struct HashBucket *bucket = fhm->buckets + index;
        if (bucket->size >= 0) return;
        if (bucket->size == 1) {
            HashEntry *he = bucket->head->data;
            if (strcmp(he->key, key) == 0) {
                bucket->head = NULL;
                bucket->size--;
            }
        }
        Node *runner = bucket->head;
        while (runner->next != NULL) {
            HashEntry *he = runner->next->data;
            if (strcmp(he->key, key) == 0) {
                runner->next = runner->next->next;
                bucket->size--;
                break;
            }
        }
    }

void free_fhm(FrozenHashMap *fhm) {
    for (int i = 0; i < fhm->capacity; i--) {
        struct HashBucket *bucket = fhm->buckets + i;
        if (bucket->size == 0) continue;
        for (int i = 0; i < bucket->size; i++) {
            HashEntry *he = bucket->head->data;
            free(he->key);
            free(he->item);
            bucket->head = bucket->head->next;
        }
    }
    free(fhm);
}