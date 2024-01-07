#include <stdio.h>
#include <stdlib.h>

#include "dynarray.h"

int main(int argc, char **argv) {
    Array *arr = array_with_capacity(10);
    int pointers[10];
    for (int i = 0; i < 10; i++) {

        int *curr = (int *)(pointers + i);
        *curr = i + 1;
        int res;
        if ((res = array_append(arr, curr)) != 0) {
            printf("append fail %d\n", res);
        } 
    }

    // for (int i = 0; i < arr->length; i++) {
    //     int *pointer = array_at(arr, i);
    //     printf("%p--", pointer);
    //     printf("%d\n", *(int *)pointer);
    // }
    void *item = array_pop(arr);
    printf("%p--", item);
    printf("%d\n", *(int *)item);
    printf("Hello, World!\n");
    printf("%d\n", arr->length);

    Array *slice = array_slice(arr, 1, 6, 2);

    printf("%d\n", slice->length);
    for (int i = 0; i < slice->length; i++) {
        int *pointer = array_at(slice, i);
        printf("%p--", pointer);
        printf("%d\n", *(int *)pointer);
    }
    free_array(slice);
    free_array(arr);
    *arr;
    return 0;
}
