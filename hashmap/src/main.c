#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashmap.h"

int main(int argc, char **argv) {
    printf("Hello, World!\n");

    HashMap *hm = hash_map();

    char *hmm = malloc(sizeof(char) * 4);
    strcpy(hmm, "cat");

    int *number = malloc(sizeof(int));
    *number = 3;
     
    char *hmm2 = malloc(sizeof(char) * 4);
    strcpy(hmm2, "car");

    int *number2 = malloc(sizeof(int));
    *number2 = 4;

    char *hmm3 = malloc(sizeof(char) * 4);
    strcpy(hmm3, "pin");

    int *number3 = malloc(sizeof(int));
    *number3 = 5;


    printf("asdsda\n");
    hm_insert(hm, hmm, number);
    hm_insert(hm, hmm2, number2);


    for (int i = 0; i < hm->capacity; i++) {
        printf("%d\n", *(hm->is_taken + i));
    }

    hm_insert(hm, hmm3, number3);

    HashEntry *he = hm_lookup(hm, hmm3);

    printf("size %d cap %d\n", hm->size, hm->capacity);

    printf("%s\n", he->key);
    printf("%d\n", *(int *)he->item);

    printf("\n");

    for (int i = 0; i < hm->capacity; i++) {
        printf("%d\n", *(hm->is_taken + i));
    }

    he = hm_delete(hm, hmm2);

    printf("%p\n", hm_lookup(hm, hmm2));
    printf("%s", he->key);
    printf(" %d\n", *(int *)he->item);

    free_hashmap(hm);
    return 0;
}
