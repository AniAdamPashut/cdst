#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H


/// @brief A simple array struct. Should'nt try to change values manually
typedef struct {
    unsigned int capacity;
    unsigned int length;
    void **items;
} Array;

/// @brief Creates a simple array
/// @return The created array
Array *array();

/// @brief Creates an array with a capacity
/// @param capacity: The capacity of the array
/// @return The created array
Array *array_with_capacity(unsigned int);

/// @brief returns the item in a specified index
/// @param arr: The array
/// @param index: The index of the item
/// @return The item in the index
void *array_at(Array *, unsigned int);

/// @brief Appends an item to the end of the array
/// @param arr: The array
/// @param item: The item
int array_append(Array *, void *);

/// @brief Inserts an item in a specific index
/// @param arr: The array
/// @param index: The index to insert in
/// @param item: The item to insert
/// @return 0 on success 1 on fail
int array_insert(Array *, unsigned int, void *);

/// @brief Returns and remove the item at the end of the array
/// @param arr: The array
/// @return The item
void *array_pop(Array *);

/// @brief Removes an item from the array
/// @param arr: The array
/// @param item: The item to remove
void array_remove(Array *, void *);

/// @brief Returns a slice of the array *does not own data*
/// @param arr: The array
/// @param start: Where to start the slice
/// @param stop: Where to stop the slice
/// @param step: The steps for the slice
/// @return A new array
Array *array_slice(Array *, unsigned int, unsigned int, unsigned int);

/// @brief A simple function to free the array
/// @param arr: The array to free
void free_array(Array *);

#endif