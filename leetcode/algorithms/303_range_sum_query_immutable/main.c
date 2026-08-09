#include <stdlib.h>

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 * numArrayFree(obj);
*/

/**
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
typedef struct {
    int* numArray;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *numArray = (NumArray*)malloc(sizeof(NumArray));
    numArray->numArray = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        numArray->numArray[i] = nums[i];
    }
    return numArray;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int sum = 0;
    for (int i = left; i <= right; i++) {
        sum += obj->numArray[i];
    }
    return sum;
}

void numArrayFree(NumArray* obj) {
    free(obj->numArray);
    free(obj);
}


// Solution
/**
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
typedef struct {
    int* prefix;
} Solution_NumArray;

Solution_NumArray* numArrayCreate(int* nums, int numsSize) {
    Solution_NumArray* obj = malloc(sizeof(Solution_NumArray));
    obj->prefix = malloc((numsSize + 1) * sizeof(int));

    obj->prefix[0] = 0;
    for (int i = 0; i < numsSize; i++)
        obj->prefix[i + 1] = obj->prefix[i] + nums[i];

    return obj;
}

int numArraySumRange(Solution_NumArray* obj, int left, int right) {
    return obj->prefix[right + 1] - obj->prefix[left];
}

void numArrayFree(Solution_NumArray* obj) {
    free(obj->prefix);
    free(obj);
}
