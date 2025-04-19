#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    *returnSize = digitsSize;
    int* result = (int*)malloc(sizeof(int) * *returnSize);
    int up = 1;

    for (int i = digitsSize - 1; i >= 0; i--) {
        int num = digits[i] + up;
        if (num >= 10) {
            num -= 10;
            up = 1;
        } else {
            up = 0;
        }

        result[i] = num;
    }

    if (up > 0) {
        (*returnSize)++;
        result = realloc(result, sizeof(int) * *returnSize);
        result[0] = 1;
        result[*returnSize - 1] = 0;
    }

    return result;
}


// Solution
// Solution 1:
int* solution1(int* digits, int digitsSize, int* returnSize) {
    *returnSize = digitsSize;
    int* plusOne = (int*)malloc(digitsSize * sizeof(int));
    if (plusOne == NULL) {
        return (NULL);
    }
    for (int i = 0; i < digitsSize; i++) {
        plusOne[i] = digits[i];
    }

    plusOne[digitsSize - 1]++;
    for (int i = digitsSize - 1; i - 1 >= 0; i--) {
        if (plusOne[i] == 10) {
            plusOne[i] = 0;
            plusOne[i - 1]++;
        }
    }

    if (plusOne[0] == 10) {
        (*returnSize)++;
        plusOne = realloc(plusOne, *returnSize * sizeof(int));
        if (plusOne == NULL) {
            return (NULL);
        }
        memmove(plusOne + 1, plusOne, digitsSize * sizeof(int));
        plusOne[0] = 1;
        plusOne[1] = 0;
    }
    return (plusOne);
}

// Solution 2:
int* solution2(int* digits, int digitsSize, int* returnSize) {
    for (int i = digitsSize - 1; i >= 0; i--) {
        digits[i]++;
        if (digits[i] < 10) {
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;
    }
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    result[0] = 1;
    for (int i = 1; i <= digitsSize; i++) {
        result[i] = 0;
    }
    *returnSize = digitsSize + 1;
    return result;
}

// Solution 3:
int* solution3(int* digits, int digitsSize, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * 100);
    int cf = 1;

    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] + cf > 9) {
            digits[i] = (digits[i] + cf) % 10;
        } else {
            digits[i] = digits[i] + cf;
            cf = 0;
            break;
        }
    }

    if (cf) {
        res[0] = 1;
    }

    for (int i = cf, j = 0; j < digitsSize; i++, j++) {
        res[i] = digits[j];
    }

    *returnSize = digitsSize + cf;
    return res;
}
