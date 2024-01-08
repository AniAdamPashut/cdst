#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H

typedef struct {
    unsigned int capacity;
    unsigned int length;
    char *value;
} String;

/// @brief Creates an empty string
/// @return A pointer to the string
String *string();

/// @brief Creates an empty string with preset capacity
/// @param capacity: The capacity of the string
/// @return A pointer to the new string
String *string_with_capacity(unsigned int);

/// @brief Creates a string from an existing cstr
/// @param str: The c string (if NULL returns a new empty string) 
/// @return A pointer to the new string
String *string_from_cstr(char *);

/// @brief Pushes a single character to the end of the string
/// @param str: The string to push onto
/// @param char: The char to push
void push_char(String *, char);

/// @brief Pushes a c string onto the string
/// @param dest: The string to push into
/// @param src: The string to push
void push_cstr(String *, char *);

/// @brief Pushes a string onto the string
/// @param dest: The string to push into
/// @param src: The string to push
void push_str(String *, String *);

/// @brief Pops a selected amount of characters from the string
/// @param str: The string to pop from
/// @param amount: The amount of characters to delete
void str_pop(String *, unsigned int);

/// @brief Set the string to a C string
/// @param str: The string to set
/// @param cstr: The C string
void str_cset(String *, char *);

/// @brief Sets the contents of a string to another string
/// @param dest: The destination string
/// @param src: The source string
void str_set(String *, String *);

/// @brief Returns a slice of a string
/// @param str: The string to slice from
/// @param start: The start of the slice
/// @param stop: Where the slice stop
/// @param step: The steps from start to stop
/// @return A new string with the slice data
String *str_slice(String *, unsigned int, unsigned int, unsigned int);

/// @brief Frees a string
/// @param str: The string to free
void free_str(String *);

#endif