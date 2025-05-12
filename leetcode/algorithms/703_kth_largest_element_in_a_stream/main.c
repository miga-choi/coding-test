#include <stdlib.h>
#include <stdio.h>

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);

 * kthLargestFree(obj);
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);

 * kthLargestFree(obj);
*/

typedef struct {
    int k;
    int length;
    int* nums;
} KthLargest;

int compare(const void* p, const void* n) {
    return (*(int*)n) - (*(int*)p);
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    KthLargest* kthLargest = (KthLargest*)malloc(sizeof(KthLargest));

    kthLargest->k = k;
    kthLargest->nums = (int*)malloc(sizeof(int) * k);

    if (numsSize < k) {
        kthLargest->length = numsSize;
        for (int i = 0; i < numsSize; i++) {
            kthLargest->nums[i] = nums[i];
        }
    } else {
        kthLargest->length = k;
        for (int i = 0; i < k; i++) {
            kthLargest->nums[i] = nums[i];
        }
    }

    return kthLargest;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->length == 0) {
        obj->nums[obj->length++] = val;
        return val;
    }

    if (obj->length < obj->k) {
        if (val < obj->nums[obj->length - 1]) {
            obj->nums[obj->length++] = val;
            return val;
        }

        obj->nums[obj->length++] = val;
        int i = obj->length - 1;
        while (i > 0 && obj->nums[i - 1] < val) {
            obj->nums[i] = obj->nums[i - 1];
            i--;
        }
        obj->nums[i] = val;

        return obj->nums[obj->length - 1];
    } else {
        if (val < obj->nums[obj->k - 1]) {
            return obj->nums[obj->k - 1];
        }

        int i = obj->k - 1;
        while (i > 0 && obj->nums[i - 1] < val) {
            obj->nums[i] = obj->nums[i - 1];
            i--;
        }
        obj->nums[i] = val;

        return obj->nums[obj->k - 1];
    }
}

void kthLargestFree(KthLargest* obj) {
    free(obj);
}


// Solution
typedef struct {
    int k;
    int* nums;
    int numsSize;
} Solution_KthLargest;

int solution_compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

Solution_KthLargest* solution_kthLargestCreate(int k, int* nums, int numsSize) {
    Solution_KthLargest* box = malloc(sizeof(Solution_KthLargest));
    box->k = k;
    box->numsSize = numsSize;
    box->nums = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        box->nums[i] = nums[i];
    }
    qsort(box->nums, box->numsSize, sizeof(int), solution_compare);
    return box;
}

int solution_kthLargestAdd(Solution_KthLargest* obj, int val) {
    obj->nums = realloc(obj->nums, (obj->k + 1) * sizeof(int));
    int i;
    for (i = obj->k - 1; i >= 0; i--) {
        if (obj->nums[i] < val) {
            obj->nums[i + 1] = obj->nums[i];
        } else {
            break;
        }
    }

    obj->nums[i + 1] = val;
    return obj->nums[obj->k - 1];
}

void solution_kthLargestFree(Solution_KthLargest* obj) {
    free(obj);
}
