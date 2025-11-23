class TwoSum {
  /**
   * Brute-Force
   *
   * Complexities:
   *   N - `nums`'s Size
   *   - Time Complexity: O(N²)
   *   - Space Complexity: O(1)
   */
  List<int> twoSum1(List<int> nums, int target) {
    for (int i = 0; i < nums.length; i++) {
      for (int j = i + 1; j < nums.length; j++) {
        if (nums[i] + nums[j] == target) {
          return [i, j];
        }
      }
    }

    return [];
  }

  /**
   * Hash Map
   *
   * Complexities:
   *   N - `nums`'s Size
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  List<int> twoSum2(List<int> nums, int target) {
    Map<int, int> map = Map<int, int>();

    for (int i = 0; i < nums.length; i++) {
      int complement = target - nums[i];
      if (map.containsKey(complement)) {
        return [i, map[complement]!];
      }
      map[nums[i]] = i;
    }

    return [];
  }


  // Solution
  /**
   * Hash Map
   *
   * Complexities:
   *   N - `nums`'s Size
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  List<int> solution(List<int> nums, int target) {
    Map<int, int> seen = {};

    for (int i = 0; i < nums.length; i++) {
      int currentNum = nums[i];
      int complement = target - currentNum;

      if (seen.containsKey(complement)) {
        return [seen[complement]!, i];
      }

      seen[currentNum] = i;
    }

    return [];
  }
}
