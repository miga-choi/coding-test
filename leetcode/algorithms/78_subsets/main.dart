class Subsets {
  /**
   * Backtracking
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N * 2ᴺ)
   *   - Space Complexity: O(N)
   */
  List<List<int>> subsets(List<int> nums) {
    List<List<int>> result = [];

    backtracking(0, nums, [], result);

    return result;
  }

  void backtracking(int start, List<int> nums, List<int> current, List<List<int>> result) {
    result.add(List.from(current));

    for (int i = start; i < nums.length; i++) {
      current.add(nums[i]);

      backtracking(i + 1, nums, current, result);

      current.removeLast();
    }
  }


  // Solution
  /**
   * Solution 1
   * 
   * Backtracking
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N * 2ᴺ)
   *   - Space Complexity: O(N)
   */
  List<List<int>> solution1(List<int> nums) {
    List<List<int>> result = [];
    List<int> current = [];

    void backtrack(int start) {
      result.add(List.from(current));

      for (int i = start; i < nums.length; i++) {
        current.add(nums[i]);

        backtrack(i + 1);

        current.removeLast();
      }
    }

    backtrack(0);

    return result;
  }

  /**
   * Solution 2
   * 
   * Cascading
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N * 2ᴺ)
   *   - Space Complexity: O(N)
   */
  List<List<int>> solution2(List<int> nums) {
    List<List<int>> result = [[]];

    for (int num in nums) {
      int size = result.length;

      for (int i = 0; i < size; i++) {
        List<int> newSubset = List.from(result[i])..add(num);
        result.add(newSubset);
      }
    }

    return result;
  }

  /**
   * Solution 3
   * 
   * Bitmasking
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N * 2ᴺ)
   *   - Space Complexity: O(N)
   */
  List<List<int>> solution3(List<int> nums) {
    List<List<int>> result = [];
    int n = nums.length;

    int subsetCount = 1 << n;

    for (int i = 0; i < subsetCount; i++) {
      List<int> subset = [];

      for (int j = 0; j < n; j++) {
        if ((i & (1 << j)) != 0) {
          subset.add(nums[j]);
        }
      }

      result.add(subset);
    }

    return result;
  }
}
