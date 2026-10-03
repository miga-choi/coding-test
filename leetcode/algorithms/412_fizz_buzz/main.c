#include <stdio.h>  // snprintf
#include <stdlib.h> // malloc
#include <string.h> // strcpy

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
char** fizzBuzz(int n, int* returnSize) {
    char** result = (char**)malloc(sizeof(char*) * n);

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            result[i - 1] = "FizzBuzz";
        } else if (i % 3 == 0) {
            result[i - 1] = "Fizz";
        } else if (i % 5 == 0) {
            result[i - 1] = "Buzz";
        } else {
            result[i - 1] = (char*)malloc(sizeof(char) * 5);
            sprintf(result[i - 1], "%d", i);
        }
    }

    *returnSize = n;
    return result;
}


// Solution
/**
 * Solution 1
 * 
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
char** solution1(int n, int* returnSize) {
    char** res = malloc(n * sizeof(char*));

    for (int i = 1; i <= n; i++) {
        char* s = malloc(9);

        if (i % 15 == 0) {
            strcpy(s, "FizzBuzz");
        } else if (i % 3 == 0) {
            strcpy(s, "Fizz");
        } else if (i % 5 == 0) {
            strcpy(s, "Buzz");
        } else {
            snprintf(s, 9, "%d", i);
        }

        res[i - 1] = s;
    }

    *returnSize = n;

    return res;
}

/**
 * Solution 2
 * 
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
char** solution2(int n, int* returnSize) {
    char** res = malloc(n * sizeof(char*));
    int c3 = 0, c5 = 0;

    for (int i = 1; i <= n; i++) {
        c3++; c5++;
        char* s = malloc(9);

        if (c3 == 3 && c5 == 5) {
            strcpy(s, "FizzBuzz");
        } else if (c3 == 3) {
            strcpy(s, "Fizz");
        } else if (c5 == 5) {
            strcpy(s, "Buzz");
        } else {
            snprintf(s, 9, "%d", i);
        }

        if (c3 == 3) {
            c3 = 0;
        }
        if (c5 == 5) {
            c5 = 0;
        }

        res[i - 1] = s;
    }

    *returnSize = n;

    return res;
}
