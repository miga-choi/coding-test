#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 1000);
    int count = 0;
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] >= 0 && nums2[j] >= 0 && nums1[i] == nums2[j]) {
                result[count] = nums1[i];
                nums1[i] = -1;
                nums2[j] = -1;
                count++;
            }
        }
    }
    *returnSize = count;
    return result;
}


// Solution
// Solution 1: Sorting
int* solution1(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int counting1[1001] = {0};
    int counting2[1001] = {0};
    
    for (int i = 0; i < nums1Size; i++) {
        counting1[nums1[i]]++;
    }
    
    for (int i = 0; i < nums2Size; i++) {
        counting2[nums2[i]]++;
    }
    
    int* res = (int*)malloc((nums1Size + nums2Size) * sizeof(int));
    int resSize = 0;
    
    for (int number = 0; number < 1001; number++) {
        int mn = counting1[number] < counting2[number] ? counting1[number] : counting2[number];
        for (int i = 0; i < mn; i++) {
            res[resSize++] = number;
        }
    }
    
    *returnSize = resSize;
    return res;
}

// Solution 2: Counting
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* solution2(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    int ind1 = 0, ind2 = 0;
    int* res = (int*)malloc((nums1Size + nums2Size) * sizeof(int));
    int resSize = 0;

    while (ind1 < nums1Size && ind2 < nums2Size) {
        int n1 = nums1[ind1];
        int n2 = nums2[ind2];
        if (n1 == n2) {
            res[resSize++] = n1;
            ind1++;
            ind2++;
        } else if (n1 > n2) {
            ind2++;
        } else {
            ind1++;
        }
    }

    *returnSize = resSize;
    return res;
}
