//
// Created by Lotte Erickson on 25/11/2019.
//

#include <stdint.h>

size_t strlen(const char* str) {
    size_t len = 0;
    while (str[len]) {
        len++;
    }
    return len;
}