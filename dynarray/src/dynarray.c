#include "dynarray.h"

#include <stdio.h>
#include <stdlib.h>

Array *array() {
    Array *arr = malloc(sizeof(Array));

    if (arr == NULL) {
        perror("malloc failed while allocating an array");
        exit(1);
    }
    arr->capacity = 0;
    arr->length = 0;
    arr->items = NULL;
    return arr;
}

Array *array_with_capacity(unsigned int capacity) {
    Array *arr = malloc(sizeof(Array));

    if (arr == NULL) {
        perror("malloc failed while allocating an array");
        exit(1);
    }
    arr->capacity = capacity;
    arr->length = 0;
    arr->items = calloc(capacity, sizeof(void *));
    if (arr->items == NULL) {
        perror("calloc failed while allocating for array items");
        exit(1);
    }
    return arr;
}

void *array_at(Array *arr, unsigned int index) {
    if (arr == NULL) {
        return NULL;
    }
    if (index >= arr->length) {
        return NULL;
    } 
    return arr->items[index];
}

int array_append(Array *arr, void *item) {
    if (arr == NULL) {
        return 1;
    }
    if (arr->length + 1 < arr->capacity) {
        arr->items[arr->length] = item;
        arr->length++;
        return 0;
    }
    void **items = calloc(arr->capacity * 2, sizeof(void *));
    if (items == NULL) {
        return 1;
    }
    for (int i = 0; i < arr->length; i++) {
        items[i] = arr->items[i];
    }
    arr->capacity *= 2;
    free(arr->items);
    arr->items = items;
    array_append(arr, item);
    return 0;
}

int 
array_insert(
    Array *arr, 
    unsigned int index, 
    void *item
) {
    if (arr == NULL) {
        return 1;
    }
    if (index >= arr->length) {
        return 1;
    }

    if (arr->length + 1 < arr->capacity) {
        for (int i = arr->length; i > index; i--) {
            arr->items[i] = arr->items[i - 1]; 
        }
        arr->items[index] = item;
    }

    void **items = calloc(arr->capacity * 2, sizeof(void *));
    if (items == NULL) {
        return 1;
    }
    for (int i = 0; i < index; i++) {
        items[i] = arr->items[i];
    }
    items[index] = item;
    for (int i = index; i < arr->length + 1; i++) {
        items[i + 1] = arr->items[i + 1];
    }
    arr->length++;
    arr->capacity *= 2;
    free(arr->items);
    arr->items = items;
    return 0;
}


void *
array_pop(Array *arr) {
    if (arr == NULL) {
        return NULL;
    }
    void *item = arr->items[--arr->length];
    return item;
}

void 
array_remove(Array *arr, void *item) {
    if (arr == NULL) {
        return;
    }
    int index = -1;
    for (int i = 0; i < arr->length; i++) {
        if (arr->items[i] == item) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("index is -1;\n");
        return;
    }
    for (int i = index; i < arr->length; i++) {
        arr->items[i] = arr->items[i + 1];
    }
    arr->length--;
}

Array *
array_slice(
    Array *arr, 
    unsigned int start, 
    unsigned int stop, 
    unsigned int step) {
        if (stop < start || stop >= arr->length) {
            return NULL;
        }
        Array *new_array = array_with_capacity((stop - start));
        for (int i = start; i < stop; i += step) {
            array_append(new_array, arr->items[i]);
        }
        return new_array;
}

void
free_array(Array *arr) {
    free(arr->items);
    free(arr);
}