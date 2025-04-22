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


  // Solution
  bool solution(List<int> nums) {
    Set<int> s = {};
    for (int n in nums) {
      if (s.contains(n)) return true;
      s.add(n);
    }
    return false;
  }
}
