import 'dart:math';

class LongestHarmoniousSubsequence {
  int findLHS(List<int> nums) {
    nums.sort();

    int result = 0, leftPin = 0, rightPin = 1;

    while (rightPin < nums.length) {
      int diff = nums[rightPin] - nums[leftPin];
      if (diff == 1) {
        result = max(rightPin - leftPin + 1, result);
        rightPin++;
      } else if (diff == 0) {
        rightPin++;
      } else {
        leftPin++;
      }
    }

    return result;
  }

  // Solution: Using Map
  int solution(List<int> nums) {
    Map<int, int> frequency = {};

    for (int num in nums) {
      frequency[num] = (frequency[num] ?? 0) + 1;
    }

    int maxLength = 0;

    for (int num in frequency.keys) {
      if (frequency.containsKey(num + 1)) {
        maxLength = max(maxLength, frequency[num]! + frequency[num + 1]!);
      }
    }

    return maxLength;
  }
}
