#include <stdlib.h>

char* toHex(int num) {
    char* hex = "0123456789abcdef";
    unsigned int unum = num;
    int count = 0;
    char* result = (char*)malloc(sizeof(char) * 9);
    result[8] = '\0';
    while (1) {
        result[7 - count] = hex[unum % 16];
        unum >>= 4;
        count++;
        if (!unum) {
            break;
        }
    }
    return &result[8 - count];
}


// Solution
char* solution(int num) {
    char* hex = (char*)malloc(sizeof(char) * 10);
    char nib;
    int i = 0;
    unsigned int x = num;
    hex[9] = '\0';
    while (1) {
        nib = (x & 0xF);
        hex[8 - i] = (nib > 9) ? ('a' + nib - 10) : ('0' + nib);
        x >>= 4;
        if (!x) break;
        i++;
    }
    return &hex[8 - i];
}
