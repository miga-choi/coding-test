class ContainsDuplicate {
  /**
   * Set
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
  bool containsDuplicate(List<int> nums) {
    if (nums.length < 2) {
      return false;
    }

    Set<int> numsSet = Set();

    for (int num in nums) {
      if (numsSet.contains(num)) {
        return true;
      } else {
        numsSet.add(num);
      }
    }

    return false;
  }


  // Solution
  /**
   * Set
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
  bool solution(List<int> nums) {
    Set<int> numsSet = Set.from(nums);
    return numsSet.length != nums.length;
  }
}
