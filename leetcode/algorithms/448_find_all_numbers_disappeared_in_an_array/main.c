#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
  int* numArray = (int*)calloc(numsSize, sizeof(int));

  for (int i = 0; i < numsSize; i++) {
    numArray[nums[i] - 1] = 1;
  }

  int* result = (int*)malloc(sizeof(int) * numsSize);
  int count = 0;

  for (int i = 1; i <= numsSize; i++) {
    if (!numArray[i - 1]) {
      result[count++] = i;
    }
  }

  *returnSize = count;
  return result;
}


// Solution
int* solution(int* nums, int numsSize, int* returnSize) {
  int m;
  for (int c = 0; c < numsSize; c++) {
    m = abs(nums[c]) - 1;
    nums[m] = -1 * abs(nums[m]);
  }

  *returnSize = 0;
  for (int c = 0; c < numsSize; c++) {
    if (nums[c] > 0) {
      (*returnSize)++;
    }
  }

  int* ret = (int*)calloc(*returnSize, sizeof(int));
  int s = 0;
  for (int c = 0; c < numsSize; c++) {
    if (nums[c] > 0) {
      ret[s++] = c + 1;
    }
  }

  return ret;
}
