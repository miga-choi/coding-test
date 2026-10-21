#include <stdlib.h> // qsort

/**
 * Sorting + Greedy
 * 
 * Complexities:
 *   N - `gSize`
 *   M - `sSize`
 *   - Time Complexity: O(N * logᴺ + M * logᴹ)
 *   - Space Complexity: O(1)
 */
int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), comp);
    qsort(s, sSize, sizeof(int), comp);

    int i = 0;

    for (int j = 0; i < gSize && j < sSize; j++) {
        if (g[i] <= s[j]) {
            i++;
        }
    }

    return i;
}


// Solution
static int cmp(const void* a, const void* b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

/**
 * Solution 1
 * 
 * Sorting + Greedy
 * 
 * Complexities:
 *   N - `gSize`
 *   M - `sSize`
 *   - Time Complexity: O(N * logᴺ + M * logᴹ)
 *   - Space Complexity: O(1)
 */
int solution1(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);

    int i = 0;
    for (int j = 0; j < sSize && i < gSize; j++) {
        if (s[j] >= g[i]) {
            i++;
        }
    }

    return i;
}

/**
 * Solution 2
 * 
 * Sorting + Greedy
 * 
 * Complexities:
 *   N - `gSize`
 *   M - `sSize`
 *   - Time Complexity: O(N * logᴺ + M * logᴹ)
 *   - Space Complexity: O(1)
 */
int solution2(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);

    int j = sSize - 1, count = 0;
    for (int i = gSize - 1; i >= 0 && j >= 0; i--) {
        if (s[j] >= g[i]) {
            count++;
            j--;
        }
    }

    return count;
}
