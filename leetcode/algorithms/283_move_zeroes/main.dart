class MoveZeroes {
  /**
   * Complexities:
   *   N - The size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  void moveZeroes(List<int> nums) {
    int zeroCount = 0;

    for (int num in nums) {
      if (num == 0) {
        zeroCount++;
      }
    }

    nums.removeWhere((int num) => num == 0);
    nums.addAll(List<int>.filled(zeroCount, 0));
  }


  // Solution
  /**
   * Two Pointers Swap
   *
   * Complexities:
   *   N - The size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  void solution(List<int> nums) {
    int slow = 0;

    for (int fast = 0; fast < nums.length; fast++) {
      if (nums[fast] != 0) {
        if (slow != fast) {
          int temp = nums[slow];
          nums[slow] = nums[fast];
          nums[fast] = temp;
        }

        slow++;
      }
    }
  }
}
