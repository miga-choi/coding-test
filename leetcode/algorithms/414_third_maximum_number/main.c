#include <limits.h>

int thirdMax(int* nums, int numsSize) {
  int first = nums[0];
  int second = INT_MIN;
  int initSecond = 0;
  int third = INT_MIN;
  int initThird = 0;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] >= first) {
      if (nums[i] == first) {
        continue;
      }
      if (!initSecond) {
        second = first;
        first = nums[i];
        initSecond = 1;
      } else {
        third = second;
        second = first;
        first = nums[i];
        initThird = 1;
      }
    } else if (nums[i] >= second) {
      if (!initSecond) {
        second = nums[i];
        initSecond = 1;
      } else {
        if (nums[i] == second) {
          continue;
        }
        third = second;
        second = nums[i];
        initThird = 1;
      }
    } else if (nums[i] >= third) {
      third = nums[i];
      initThird = 1;
    }
  }

  if (!initThird) {
    return first;
  }

  return third;
}


// Solution
int solution(int* nums, int numsSize) {
  int max_1 = nums[0];
  long max_2 = LONG_MIN;
  long max_3 = LONG_MIN;

  for (int i = 1; i < numsSize; i++) {
    if (nums[i] > max_1) {
      max_3 = max_2;
      max_2 = max_1;
      max_1 = nums[i];
    } else if (nums[i] > max_2 && nums[i] < max_1) {
      max_3 = max_2;
      max_2 = nums[i];
    } else if (nums[i] > max_3 && nums[i] < max_2) {
      max_3 = nums[i];
    }
  }

  return (max_3 == LONG_MIN) ? max_1 : max_3;
}
