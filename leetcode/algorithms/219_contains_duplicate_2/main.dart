class ContainsDuplicateII {
  /**
   * Hash Map
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
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


  // Solution
  /**
   * Solution 1
   *
   * Sliding Window + Hash Set
   *
   * Complexities:
   *   N - Size of `nums`
   *   K - `k`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(min(N, K))
   */
  bool solution1(List<int> nums, int k) {
    final Set<int> window = {};

    for (int i = 0; i < nums.length; i++) {
      if (i > k) {
        window.remove(nums[i - k - 1]);
      }

      if (!window.add(nums[i])) {
        return true;
      }
    }

    return false;
  }

  /**
   * Solution 2
   *
   * Hash Map
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  bool solution2(List<int> nums, int k) {
    final Map<int, int> lastSeen = {};

    for (int i = 0; i < nums.length; i++) {
      int num = nums[i];

      if (lastSeen.containsKey(num) && (i - lastSeen[num]!) <= k) {
        return true;
      }

      lastSeen[num] = i;
    }

    return false;
  }
}
