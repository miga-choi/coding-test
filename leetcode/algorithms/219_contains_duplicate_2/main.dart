class ContainsDuplicateII {
  bool containsNearbyDuplicate(List<int> nums, int k) {
    Map<int, int> numsMap = Map();
    for (int i = 0; i < nums.length; i++) {
      if (numsMap[nums[i]] == null) {
        numsMap[nums[i]] = i;
      } else {
        if ((numsMap[nums[i]]! - i).abs() <= k) {
          return true;
        }
        numsMap[nums[i]] = i;
      }
    }
    return false;
  }

  // Best Solution
  bool bestSolution(List<int> nums, int k) {
    for (int i = 0; i < nums.length; i++) {
      for (int j = i + 1; j < nums.length && j <= i + k; j++) {
        if ((nums[i] == nums[j])) {
          return true;
        }
      }
    }
    return false;
  }
}
