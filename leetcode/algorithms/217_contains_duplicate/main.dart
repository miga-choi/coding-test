class ContainsDuplicate {
  /**
   * Hash Set
   *
   * Complexities:
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
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
   * Solution 1
   *
   * Hash Set
   *
   * Complexities:
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  bool solution1(List<int> nums) {
    final Set<int> seen = {};

    for (final num in nums) {
      if (!seen.add(num)) {
        return true;
      }
    }

    return false;
  }

  /**
   * Solution 2
   *
   * Sort
   *
   * Complexities:
   *   - Time Complexity: O(N * logᴺ)
   *   - Space Complexity: O(1)
   */
  bool solution2(List<int> nums) {
    if (nums.length < 2) {
      return false;
    }

    nums.sort();

    for (int i = 1; i < nums.length; i++) {
      if (nums[i] == nums[i - 1]) {
        return true;
      }
    }

    return false;
  }
}
