#include <stdlib.h>

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 * numArrayFree(obj);
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
typedef struct {
    int* arr;
} Solution_NumArray;

Solution_NumArray* solution_numArrayCreate(int* nums, int numsSize) {
    Solution_NumArray* ptr = (Solution_NumArray*)malloc(sizeof(Solution_NumArray));
    ptr->arr = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        ptr->arr[i] = nums[i];
    }
    return ptr;
}

int solution_numArraySumRange(Solution_NumArray* obj, int left, int right) {
    int sum = 0;
    for (int i = left; i <= right; i++) {
        sum += obj->arr[i];
    }
    return sum;
}

void solution_numArrayFree(Solution_NumArray* obj) {
    free(obj->arr);
    free(obj);
}
