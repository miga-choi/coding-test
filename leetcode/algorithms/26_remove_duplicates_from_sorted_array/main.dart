class RemoveDuplicatesFromSortedArray {
  /**
   * Two Pointers
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
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
   * - Time Complexity: O(Nlogᴺ)
   * - Space Complexity: O(N)
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
  int solution(List<int> nums) {
    int k = 0;
    for (int i = 1; i < nums.length; i++) {
      if (nums[i - 1] != nums[i]) {
        k++;
        nums[k] = nums[i];
      }
    }
    return k + 1;
  }
}
