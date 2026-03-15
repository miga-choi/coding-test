class Permutations {
  /**
   * Backtracking
   * 
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N * N!)
   *   - Space Complexity: O(N)
   */
  List<List<int>> permute(List<int> nums) {
    List<List<int>> result = [];
    List<bool> visited = List<bool>.filled(nums.length, false);

    void backtracking(List<int> current) {
      if (current.length == nums.length) {
        result.add(List.from(current));
        return;
      }

      for (var i = 0; i < nums.length; i++) {
        if (visited[i]) {
          continue;
        }

        current.add(nums[i]);
        visited[i] = true;

        backtracking(current);

        current.removeLast();
        visited[i] = false;
      }
    }

    backtracking([]);

    return result;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Backtracking: Visited Array
   * 
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N * N!)
   *   - Space Complexity: O(N)
   */
  List<List<int>> solution1(List<int> nums) {
    List<List<int>> result = [];
    List<int> current = [];
    List<bool> visited = List.filled(nums.length, false);

    void backtrack() {
      if (current.length == nums.length) {
        result.add(List.from(current));
        return;
      }

      for (int i = 0; i < nums.length; i++) {
        if (visited[i]) {
          continue;
        }

        visited[i] = true;
        current.add(nums[i]);

        backtrack();

        current.removeLast();
        visited[i] = false;
      }
    }

    backtrack();

    return result;
  }

  /**
   * Solution 2
   * 
   * Backtracking: In-place Swapping
   * 
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N * N!)
   *   - Space Complexity: O(N)
   */
  List<List<int>> solution2(List<int> nums) {
    List<List<int>> result = [];

    void backtrack(int start) {
      if (start == nums.length) {
        result.add(List.from(nums));
        return;
      }

      for (int i = start; i < nums.length; i++) {
        _swap(nums, start, i);

        backtrack(start + 1);

        _swap(nums, start, i);
      }
    }

    backtrack(0);
    return result;
  }

  void _swap(List<int> list, int i, int j) {
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
  }
}
