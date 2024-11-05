class ContainsDuplicate {
  bool containsDuplicate(List<int> nums) {
    Map<int, bool> numsMap = Map<int, bool>();
    for (int i = 0; i < nums.length; i++) {
      if (numsMap[nums[i]] == true) {
        return true;
      } else {
        numsMap[nums[i]] = true;
      }
    }
    return false;
  }

  // Best Solution
  bool bestSolution(List<int> nums) {
    return false;
  }
}
