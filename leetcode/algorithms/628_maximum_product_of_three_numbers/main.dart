import 'dart:math';

class MaximumProductOfThreeNumbers {
  int maximumProduct(List<int> nums) {
    int max1 = -1000, max2 = -1000, max3 = -1000;
    int min1 = 1000, min2 = 1000;

    for (int num in nums) {
      if (num > max1) {
        max3 = max2;
        max2 = max1;
        max1 = num;
      } else if (num > max2) {
        max3 = max2;
        max2 = num;
      } else if (num > max3) {
        max3 = num;
      }

      if (num < min1) {
        min2 = min1;
        min1 = num;
      } else if (num < min2) {
        min2 = num;
      }
    }

    return max(max1 * max2 * max3, min1 * min2 * max1);
  }

  // Solution
  int solution(List<int> nums) {
    nums.sort();
    return max(
      nums[0] * nums[1] * nums[nums.length - 1],
      nums[nums.length - 1] * nums[nums.length - 2] * nums[nums.length - 3],
    );
  }
}
