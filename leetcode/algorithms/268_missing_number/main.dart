class MissingNumber {
  int missingNumber(List<int> nums) {
    int result = 0;
    for (int i = 0; i < nums.length; i++) {
      result = result ^ (i + 1) ^ nums[i];
    }
    return result;
  }


  // Solution
  // Solution 1
  int solution1(List<int> nums) {
    nums.sort();
    int count = 0;
    int result = 0;
    if (nums[0] != 0) return 0;
    for (var i = 0; nums.length > i; i++) {
      if (nums[i] != i) {
        result = nums[i - 1] + 1;
        count++;
        break;
      }
    }
    if (count == 0) {
      result = nums.last + 1;
    }
    return result;
  }

  // Solution 2
  int solution2(List<int> nums) {
    int n = nums.length;
    int sum = nums.reduce((a, b) => a + b);
    return n * (n + 1) ~/ 2 - sum;
  }
}
