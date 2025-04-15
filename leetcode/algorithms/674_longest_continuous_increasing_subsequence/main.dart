class LongestContinuousIncreasingSubsequence {
  int findLengthOfLCIS(List<int> nums) {
    int res = 1, count = 1;
    for (int i = 1; i < nums.length; i++) {
      if (nums[i] > nums[i - 1]) {
        count++;
        if (count > res) {
          res = count;
        }
      } else {
        count = 1;
      }
    }
    return res;
  }
}
