#include <stdlib.h> // malloc

/**
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
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
/**
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
char* solution(int num) {
    static const char DIGITS[] = "0123456789abcdef";
    char* res = malloc(9);

    if (num == 0) {
        res[0] = '0';
        res[1] = '\0';
        return res;
    }

    unsigned int u = (unsigned int)num;
    char buf[8];
    int len = 0;

    while (u != 0) {
        buf[len++] = DIGITS[u & 0xF];
        u >>= 4;
    }

    for (int i = 0; i < len; i++) {
        res[i] = buf[len - 1 - i];
    }

    res[len] = '\0';

    return res;
}
