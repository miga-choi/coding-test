#include <ctype.h>  // toupper
#include <stdlib.h> // malloc
#include <string.h> // stdlen

/**
 * Single-Pass Backward Fill with Positional Dash Insertion
 * 
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
char* licenseKeyFormatting(char* s, int k) {
    int length = strlen(s);
    int p = length - 1;

    char* result = (char*)malloc(sizeof(char) * (length * 2));
    result[length * 2 - 1] = '\0';
    int i = 1;

    while (1) {
        if (p < 0) {
            break;
        }
        if (s[p] == '-') {
            p--;
            continue;
        }

        if (!(i % (k + 1))) {
            result[length * 2 - 1 - i] = '-';
        } else {
            result[length * 2 - 1 - i] = s[p] >= 'a' ? s[p] - 'a' + 'A' : s[p];
            p--;
        }

        i++;
    }

    return &result[length * 2 - i];
}


// Solution
/**
 * Solution 1
 * 
 * Two-Pass + Backward Fill
 * 
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
char* solution1(char* s, int k) {
    int n = 0, cnt = 0;

    for (; s[n]; n++) {
        if (s[n] != '-') {
            cnt++;
        }
    }

    int len = (cnt == 0) ? 0 : cnt + (cnt - 1) / k;
    char* res = malloc(len + 1);
    res[len] = '\0';

    int pos = len - 1, group = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '-') {
            continue;
        }

        if (group == k) {
            res[pos--] = '-';
            group = 0;
        }

        res[pos--] = (char)toupper((unsigned char)s[i]);
        group++;
    }

    return res;
}


/**
 * Solution 2
 * 
 * Two-Pass + Forward Fill with First Group Size
 * 
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
char* solution2(char* s, int k) {
    int cnt = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] != '-') {
            cnt++;
        }
    }

    int len = (cnt == 0) ? 0 : cnt + (cnt - 1) / k;
    char* res = malloc(len + 1);

    int limit = cnt % k;
    if (limit == 0) {
        limit = k;
    }

    int pos = 0, group = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '-') {
            continue;
        }

        if (group == limit) {
            res[pos++] = '-';
            group = 0;
            limit = k;
        }

        res[pos++] = (char)toupper((unsigned char)s[i]);
        group++;
    }

    res[pos] = '\0';
    return res;
}
