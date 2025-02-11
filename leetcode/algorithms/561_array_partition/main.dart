import 'dart:math';

class ArrayPartition {
  int arrayPairSum(List<int> nums) {
    nums.sort();
    int result = 0;
    for (int i = 0; i < nums.length; i += 2) {
      result += nums[i];
    }
    return result;
  }

  // Solution
  int solution(List<int> nums) {
    nums.sort((a, b) => b.compareTo(a));
    int sum = 0;
    for (int i = 0; i < nums.length; i++) {
      if (i % 2 != 0) {
        sum += min(nums[i], nums[i - 1]);
      }
    }
    return sum;
  }
}
