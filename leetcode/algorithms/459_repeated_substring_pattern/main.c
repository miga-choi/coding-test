#include <stdbool.h> // bool
#include <stdlib.h>  // free, malloc
#include <string.h>  // memcpy, strlen, strstr

bool repeatedSubstringPattern(char* s) {}


// Solution
/**
 * Solution 1
 *
 * Brute Force
 *
 * Complexities:
 *   N - The Size of `s`
 *   d(N) - The Number of Divisors of N 
 *   - Time Complexity: O(N * d(N))
 *   - Space Complexity: O(1)
 */
bool solution1(char* s) {
    int n = (int)strlen(s);

    for (int len = 1; len <= n / 2; len++) {
        if (n % len != 0) {
            continue;
        }

        int i = len;
        while (i < n && s[i] == s[i - len]) {
            i++;
        }

        if (i == n) {
            return true;
        }
    }

    return false;
}

/**
 * Solution 2
 *
 * String Concatenation
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N) ~ O(N²)
 *   - Space Complexity: O(N)
 */
bool solution2(char* s) {
    size_t n = strlen(s);
    char* ss = malloc(2 * n + 1);

    memcpy(ss, s, n);
    memcpy(ss + n, s, n);
    ss[2 * n - 1] = '\0';

    bool ans = strstr(ss + 1, s) != NULL;

    free(ss);
    return ans;
}

/**
 * Solution 3
 *
 * KMP Prefix Function
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
bool solution3(char* s) {
    int n = (int)strlen(s);
    int* lps = malloc(n * sizeof(int));
    lps[0] = 0;

    for (int i = 1, len = 0; i < n; i++) {
        while (len > 0 && s[i] != s[len]) {
            len = lps[len - 1];
        }

        if (s[i] == s[len]) {
            len++;
        }

        lps[i] = len;
    }

    int l = lps[n - 1];

    free(lps);
    return l > 0 && n % (n - l) == 0;
}
