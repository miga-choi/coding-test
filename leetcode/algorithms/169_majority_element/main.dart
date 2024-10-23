class MajorityElement {
  int majorityElement(List<int> nums) {
    int result = 0;
    int count = 0;
    for (int num in nums) {
      if (count == 0) {
        result = num;
      }
      if (result == num) {
        count++;
      } else {
        count--;
      }
    }
    return result;
  }

  // Best Solution
  int bestSolution(List<int> nums) {
    nums.sort();
    return nums[nums.length ~/ 2];
  }
}
