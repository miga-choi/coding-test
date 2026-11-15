#include <math.h>   // sqrt
#include <stdlib.h> // malloc

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * Divisor Search from 1 Upward
 * 
 * Complexities:
 *   n - `area`
 *   - Time Complexity: O(√n)
 *   - Space Complexity: O(1)
 */
int* constructRectangle(int area, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 2);
    int diff = area;

    for (int i = 1; i <= sqrt(area); i++) {
        if ((area % i) == 0) {
            if (abs((area / i) - i) < diff) {
                result[0] = area / i;
                result[1] = i;
            }
        }
    }

    *returnSize = 2;
    return result;
}


// Solution
/**
 * Solution 1
 * 
 * Divisor Search from √area Downward
 * 
 * Complexities:
 *   n - `area`
 *   - Time Complexity: O(√n)
 *   - Space Complexity: O(1)
 */
int* solution1(int area, int* returnSize) {
    int w = (int)sqrt((double)area);

    while (w * w > area) {
        w--;
    }

    while ((w + 1) * (w + 1) <= area) {
        w++;
    }

    while (area % w != 0) {
        w--;
    }

    int* res = malloc(2 * sizeof(int));
    res[0] = area / w;
    res[1] = w;

    *returnSize = 2;

    return res;
}

/**
 * Solution 2
 * 
 * Divisor Search from 1 Upward
 * 
 * Complexities:
 *   n - `area`
 *   - Time Complexity: O(√n)
 *   - Space Complexity: O(1)
 */
int* solution2(int area, int* returnSize) {
    int best = 1;

    for (int w = 1; w * w <= area; w++) {
        if (area % w == 0) {
            best = w;
        }
    }

    int* res = malloc(2 * sizeof(int));
    res[0] = area / best;
    res[1] = best;

    *returnSize = 2;

    return res;
}
