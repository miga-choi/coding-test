class RemoveDuplicatesFromSortedArray {
  /**
   * Two Pointers
   * 
   * Complexities:
   *   N - Length of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int removeDuplicates1(List<int> nums) {
    int left = 0;

    for (int right = 0; right < nums.length; right++) {
      if (nums[left] != nums[right]) {
        nums[++left] = nums[right];
      }
    }

    return left + 1;
  }

  /**
   * Set
   * 
   * Complexities:
   *   N - Length of `nums`
   *   - Time Complexity: O(N * logᴺ)
   *   - Space Complexity: O(N)
   */
  int removeDuplicates2(List<int> nums) {
    List<int> numsSet = Set<int>.from(nums).toList();
    numsSet.sort((int p, int n) => p - n);

    int i = 0;

    for (; i < numsSet.length; i++) {
      nums[i] = numsSet[i];
    }

    return i;
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
  int solution(List<int> nums) {
    int j = 1;

    for (int i = 1; i < nums.length; i++) {
      if (nums[i] != nums[i - 1]) {
        nums[j] = nums[i];
        j++;
      }
    }

    return j;
  }
}
