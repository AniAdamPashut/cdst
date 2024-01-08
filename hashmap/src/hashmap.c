#include "hashmap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HashMap *hash_map() {
    HashMap *hm = malloc(sizeof(HashMap));
    if (hm == NULL) {
        return NULL;
    }
    hm->capacity = 2;
    hm->size = 0;
    hm->entries = calloc(hm->capacity, sizeof(HashEntry));
    hm->is_taken = calloc(hm->capacity, sizeof(int));
    return hm;
}

HashMap *
hash_map_with_capacity(
    unsigned int capacity
) {
    HashMap *hm = malloc(sizeof(HashMap));
    if (hm == NULL) {
        perror("malloc failed while creating a hashmap");
        exit(1);
    }

    hm->capacity = capacity;
    hm->size = 0;
    hm->entries = calloc(capacity, sizeof(HashEntry));
    if (hm->entries == NULL) {
        perror("calloc failed while creating hashmap entries");
        exit(1);
    }
    hm->is_taken = calloc(capacity, sizeof(int));
}

HashEntry *
hm_lookup(
    HashMap *hm, 
    char *key
) {
    if (hm == NULL || key == NULL) {
        return NULL;
    }

    unsigned int hash_of_key = hash(key);
    unsigned int index = hash_of_key % hm->capacity;

    HashEntry *he = hm->entries + index;

    while (
        index < hm->capacity 
        && hm->is_taken[index] == 1
        && strcmp(he->key, key) != 0) {
            index++;
            he = hm->entries + index;
        } 
    
    if (hm->is_taken[index] == 1) {
        return he;
    }
    return NULL;
}

void
hm_insert(
    HashMap *hm,
    char *key,
    void *item
) {
    if (hm == NULL // The hashmap is null
        || key == NULL // The key is null
        || item == NULL // The value is null
        || hm_lookup(hm, key) != NULL // The already in the table
        ) {
            return;
        }

    if (hm->capacity == 0) {
        hm->capacity = 4;
    }
    double load_factor = (float)(hm->size + 1) / (float)hm->capacity;
    if (load_factor > 0.6) {
        HashEntry *new_entries = calloc(hm->capacity * 2, sizeof(HashEntry));
        if (new_entries == NULL) {
            perror("calloc failed while allocating space for another entries array\n");
            exit(1);
        }
        int *new_taken = calloc(hm->capacity * 2, sizeof(int));
        if (new_taken == NULL) {
            perror("calloc failed while allocating space for another is_taken array\n");
            exit(1);
        }
        for (int i = 0; i < hm->capacity; i++) {
            if (hm->is_taken[i] == 0) {
                continue;
            }
            HashEntry *original = hm->entries + i;
            unsigned int hash_of_entry = hash(original->key);
            unsigned int index_of_entry = hash_of_entry % (hm->capacity * 2);
            while (
                index_of_entry < hm->capacity * 2
                && new_taken[index_of_entry] == 1) {
                index_of_entry++;
            }

            HashEntry *he = new_entries + index_of_entry;
            if (he != NULL) {
            }
            he->key = original->key;
            he->item = original->item;
            new_taken[index_of_entry] = 1;
            
        }
        hm->capacity *= 2;
        free(hm->entries);
        hm->entries = new_entries;
        free(hm->is_taken);
        hm->is_taken = new_taken;
    }
    unsigned int hash_of_target = hash(key);
    unsigned int index = hash_of_target % hm->capacity;

    while (
        index < hm->capacity
        && hm->is_taken[index] == 1) {
        index++;
    }

    if (index < hm->capacity) {
        HashEntry *he = hm->entries + index;
        
        he->key = key;
        he->item = item;
        hm->is_taken[index] = 1;
        hm->size++;
    }
}

HashEntry *
hm_delete(
    HashMap *hm,
    char *key
) {
    if (
        hm == NULL
        || key == NULL
        || hm_lookup(hm, key) == NULL) {
            return NULL;
        }
    
    unsigned int hash_of_key = hash(key);
    unsigned int index = hash_of_key % hm->capacity;

    HashEntry *he = hm->entries + index;

    while (
        index < hm->capacity 
        && hm->is_taken[index] == 1
        && strcmp(he->key, key) != 0) {
            index++;
            he = hm->entries + index;
        } 
    
    if (hm->is_taken[index] == 1) {
        hm->is_taken[index] = 0;
        return he;
    }

    return NULL;

}

void
free_hashmap(
    HashMap *hm
) {
    for (int i = 0; i < hm->capacity; i++) {
        if (hm->is_taken[i] == 0) continue;
        free((hm->entries + i)->item);
        free((hm->entries + i)->key);
    }
    free(hm->entries);
    free(hm->is_taken);
    free(hm);
}