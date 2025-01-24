#include <stdlib.h>

char* convertToBase7(int num) {
    if (!num) {
        return "0";
    }

    char* result = (char*)malloc(sizeof(char) * 11);
    int negative = 0;
    result[10] = '\0';
    int count = 0;

    if (num < 0) {
        negative = 1;
        num *= -1;
    }

    while (num > 0) {
        result[10 - (++count)] = num % 7 + '0';
        num /= 7;
    }

    if (negative) {
        result[10 - (++count)] = '-';
    }

    return &result[10 - count];
}

// Solution
char* solution(int num) {
    int sz = 0;
    char* v = (char*)malloc(sizeof(char) * 16);

    int mask = num >> 31;
    num = (num ^ mask) - mask;
    int neg = !!mask;
    v[sz] = '-';
    sz |= neg; /* sz += 1 */

    do {
        v[sz++] = (num % 7) + '0';
        num /= 7;
    } while (num);

    for (int i = neg, j = sz - 1; i < j; i++, j--) {
        char t = v[i];
        v[i] = v[j];
        v[j] = t;
    }
    v[sz] = '\0';

    return v;
}
