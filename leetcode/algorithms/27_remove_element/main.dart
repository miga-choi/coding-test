class RemoveElement {
  /**
   * Two Pointers
   *
   * Complexities:
   *   N - Length of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int removeElement(List<int> nums, int val) {
    nums.removeWhere((e) => e == val);

    return 0;
  }


  // Solution
  /**
   * Two Pointers
   *
   * Complexities:
   *   N - Length of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution(List<int> nums, int val) {
    int k = 0;

    for (int i = 0; i < nums.length; i++) {
      if (nums[i] != val) {
        nums[k] = nums[i];
        k++;
      }
    }

    return k;
  }
}
