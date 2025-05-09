#include <stdlib.h>

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);

 * kthLargestFree(obj);
*/

typedef struct {

} KthLargest;

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {

}

int kthLargestAdd(KthLargest* obj, int val) {

}

void kthLargestFree(KthLargest* obj) {
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
