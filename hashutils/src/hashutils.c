#include "hashutils.h"

#include <string.h>

unsigned int hash(char *key) {
    unsigned int sumprod = 0;
    for (int i = 0; i < strlen(key); i++) {
        sumprod += key[i];
        sumprod *= key[i];
    }
    return sumprod;
}