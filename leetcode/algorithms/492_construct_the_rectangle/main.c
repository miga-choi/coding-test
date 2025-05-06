#include <math.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
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
int* solution(int area, int* returnSize) {
    int* arr = (int*)malloc(sizeof(int) * 2);
    int width = sqrt(area);

    while (area % width != 0) {
        width--;
    }

    arr[0] = area / width;
    arr[1] = width;

    *returnSize = 2;

    return arr;
}
