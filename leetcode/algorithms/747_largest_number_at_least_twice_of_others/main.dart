class LargestNumberAtLeastTwiceOfOthers {
  int dominantIndex(List<int> nums) {
    int max = -1;
    int second = -1;
    int index = -1;

    for (int i = 0; i < nums.length; i++) {
      if (nums[i] > max) {
        second = max;
        max = nums[i];
        index = i;
      } else if (nums[i] > second) {
        second = nums[i];
      }
    }

    return max >= second * 2 ? index : -1;
  }


  // Solution
  int solution(List<int> nums) {
    int max = -1, index = -1, second = -1;

    for (int i = 0; i < nums.length; i++) {
      if (nums[i] > max) {
        second = max;
        max = nums[i];
        index = i;
      } else if (nums[i] > second) {
        second = nums[i];
      }
    }

    return second * 2 <= max ? index : -1;
  }
}
