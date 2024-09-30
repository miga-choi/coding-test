class RemoveDuplicatesFromSortedArray {
  int removeDuplicates(List<int> nums) {
    if (nums.length == 0) {
      return 0;
    }

    int j = 1;
    for (int i = 1; i < nums.length; i++) {
      if (nums[i] != nums[j - 1]) {
        nums[j] = nums[i];
        j++;
      }
    }

    return j;
  }

  // Best Solution
  int BestSolution(List<int> nums) {
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
