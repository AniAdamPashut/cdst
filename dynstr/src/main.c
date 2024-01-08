#include <stdio.h>

#include "dynstr.h"

void print_string(String *);

int main(int argc, char **argv) {
    String *str = string_with_capacity(10);

    push_cstr(str, "cat");

    push_char(str, '4');
    print_string(str);

    str_pop(str, 2);

    print_string(str);
    str_cset(str, "I Love Writing these string");


    String *str2 = string_from_cstr("LOLOLOLaosdadadasd");
    print_string(str2);
    print_string(str);
    printf("%d The length in main\n", str2->length);
    printf("%p str\n", str);
    printf("%p str2\n", str2);
    printf("%p diff\n", str2 - str);
    push_str(str, str2);
    printf("%d THe length after\n", str->length);
    print_string(str);
    printf("Hello, World!\n");
    String *str3 = str_slice(str, 0, 45, 5);
    print_string(str3);
    return 0;
    free_str(str);
    free_str(str2);
    free_str(str3);
}

void print_string(String *str) {
    for (int i = 0; i < str->length; i++) {
        printf("%c", str->value[i]);
    }
    printf("\n");
}
