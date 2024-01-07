#include "hashutils.h"

#include <string.h>

unsigned int hash(char *key) {
    unsigned int sum_product = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum_product += key[i];
        sum_product *= key[i];
    }
    return sum_product;
}