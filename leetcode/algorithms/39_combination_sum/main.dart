class CombinationSum {
  /**
   * Backtracking
   * 
   * Complexities:
   *   N - Size of `candidates`
   *   T - Value of `target`
   *   M - Minimum value of `candidates`
   *   - Time Complexity: O(Nᵀ/ᴹ)
   *   - Space Complexity: O(T/M)
   */
  void backtracking(
    List<int> candidates,
    int target,
    int start,
    List<int> current,
    List<List<int>> result,
  ) {
    if (target == 0) {
      result.add(List.from(current));
      return;
    }

    if (target < 0) {
      return;
    }

    for (int i = start; i < candidates.length; i++) {
      current.add(candidates[i]);

      backtracking(candidates, target - candidates[i], i, current, result);

      current.removeLast();
    }
  }

  List<List<int>> combinationSum(List<int> candidates, int target) {
    List<List<int>> result = [];
    List<int> current = [];

    backtracking(candidates, target, 0, current, result);

    return result;
  }


  // Solution
  /**
   * Backtracking
   * 
   * Complexities:
   *   N - Size of `candidates`
   *   T - Value of `target`
   *   M - Minimum value of `candidates`
   *   - Time Complexity: O(Nᵀ/ᴹ)
   *   - Space Complexity: O(T/M)
   */
  List<List<int>> solution(List<int> candidates, int target) {
    List<List<int>> result = [];
    List<int> currentCombination = [];

    candidates.sort();

    void backtrack(int remain, int start) {
      if (remain == 0) {
        result.add(List.from(currentCombination));
        return;
      }

      for (int i = start; i < candidates.length; i++) {
        if (candidates[i] > remain) {
          break;
        }

        currentCombination.add(candidates[i]);

        backtrack(remain - candidates[i], i);

        currentCombination.removeLast();
      }
    }

    backtrack(target, 0);

    return result;
  }
}
