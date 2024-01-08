#include "dynstr.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

String *string() {
    String *str = malloc(sizeof(String));
    str->capacity = 1;
    str->length = 0;
    str->value = malloc(sizeof(char));
    return str;
}

String *
string_with_capacity(
    unsigned int capacity
) {
    String *str = malloc(sizeof(String));
    str->capacity = capacity;
    str->length = 0;
    str->value = malloc(sizeof(char) * capacity);
    return str;
}

String *
string_from_cstr(
    char *str
) {
    String *string = malloc(sizeof(String));
    unsigned int length = strlen(str);
    string->capacity = length * 2;
    string->length = length;
    string->value = malloc(sizeof(char) * string->capacity);
    strncpy(string->value, str, length);
    return string;
}

void
push_char(
    String *str,
    char character
) {
    if (str->length + 1 >= str->capacity) {
        str->value = realloc(str->value, sizeof(char) * str->capacity * 2);
        str->value[str->length] = character;
        str->length++;
        return;
    }
    str->value[str->length] = character;
    str->length++;
}

void 
push_cstr(
    String *str,
    char *cstr
) {
    int length = strlen(cstr);
    if (str->length + length + 1 >= str->capacity) {
        char *new_string = malloc(str->capacity * 2 + str->length);
        memcpy(new_string, str->value, str->length);
        memcpy(new_string + str->length, cstr, length);
        free(str->value);
        str->value = new_string;
        return;
    }
    strcpy(str->value + str->length, cstr);
    str->length += length;
}

void 
push_str(
    String *dest,
    String *src
) {
    int length = src->length;
    if (dest->length + length + 1 >= dest->capacity) {
        dest->value = realloc(dest->value, sizeof(char) * dest->capacity + length);
    }
    strncpy(dest->value + dest->length, src->value, length);
    dest->length += length;
}

void
str_pop(
    String *str,
    unsigned int amount
) {
    if (amount > str->length) {
        str->length = 0;
        return;
    }
    str->length -= amount;
}

void 
str_cset(
    String *str,
    char *cstr
) {
    int length = strlen(cstr);
    if (length > str->capacity) {
        str->capacity = str->capacity * 2 + length;
        str->value = realloc(str->value, sizeof(char) * str->capacity);
        strncpy(str->value, cstr, length);
        str->length = length;
        return;
    }
    str->length = length;
    strncpy(str->value, cstr, length);
}

void
str_set(
    String *dest,
    String *src
) {
    if (src->length > dest->capacity) {
        dest->capacity = dest->capacity * 2 + src->length;
        dest->value = realloc(dest->value, sizeof(char) * dest->capacity);
        strncpy(dest->value, src->value, src->length);
        dest->length = src->length;
        return;
    }
    char *new_string = malloc(dest->capacity);
    int length = src->length;
    strncpy(new_string, src->value, src->length);
    strncpy(dest->value, new_string, length);
    dest->length = length; 
}

String *
str_slice(
    String *str,
    unsigned int start,
    unsigned int stop,
    unsigned int step
) {
    if (stop > str->length 
        || start >= stop) {
            return NULL;
        }
    String *new_str = string();
    for (int i = start; i < stop; i += step) {
        push_char(new_str, str->value[i]);
    }
    return new_str;
}

void
free_string(
    String *str
) {
    free(str->value);
    free(str);
}