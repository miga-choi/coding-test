class SetMismatch {
  List<int> findErrorNums(List<int> nums) {
    int duplicatedNum = -1, missedNum = -1;

    for (int i = 1; i <= nums.length; i++) {
      int count = 0;
      for (int num in nums) {
        if (num == i) {
          count++;
        }
      }
      if (count == 2) {
        duplicatedNum = i;
      }
      if (count == 0) {
        missedNum = i;
      }
    }

    return [duplicatedNum, missedNum];
  }

  // Solution: Using Map
  List<int> solution(List<int> nums) {
    Map<int, int> countMap = {};
    List<int> res = [];

    int repeatedNumber = 0;
    int expectedSum = (nums.length * (nums.length + 1)) ~/ 2;
    int actualSum = 0;

    for (var i = 0; i < nums.length; i++) {
      countMap[nums[i]] = (countMap[nums[i]] ?? 0) + 1;
      actualSum += nums[i];

      if (countMap[nums[i]] == 2) {
        repeatedNumber = nums[i];
      }
    }

    int missingNumber = expectedSum - (actualSum - repeatedNumber);

    res.add(repeatedNumber);
    res.add(missingNumber);

    return res;
  }
}
