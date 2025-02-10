#include <stdlib.h>

int compare(const void* element1, const void* element2) {
    int e1 = *((int*)element1);
    int e2 = *((int*)element2);
    if (e1 > e2) {
        return 1;
    }
    if (e2 < e1) {
        return -1;
    }
    return 0;
}

int arrayPairSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int result = 0;
    for (int i = 0; i < numsSize; i += 2) {
        result += nums[i];
    }
    return result;
}

// Solution
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int solution(int* nums, int numsSize) {
    int res = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; i += 2) {
        res += nums[i];
    }
    return res;
}
