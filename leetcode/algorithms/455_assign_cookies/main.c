#include <stdlib.h>

// Custom comparator
int comp(const void* a, const void* b) {
    // If a is smaller, positive value will be returned
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
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int solution(int* g, int gSize, int* s, int sSize) {
    /* Sort two arrays */
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);

    int result = 0;
    int i = 0;
    int j = 0;

    /* Using two pointers to search that the content the child could get smaller as possile cookie */
    while (i < gSize && j < sSize) {
        // Skip the cookie no child want it
        while (j < sSize && g[i] > s[j]) {
            ++j;
        }

        if (i < gSize && j < sSize) {
            ++result;
        }

        ++i;
        ++j;
    }

    return result;
}
