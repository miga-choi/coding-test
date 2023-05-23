class Solution {

  public int singleNumber(int[] nums) {
    int result = 0;
    for (int num : nums) {
      result = result ^ num;
    }
    return result;
  }

  // Best Solution
  public int bestSolution(int[] nums) {
    int result = 0;
    for (int i = 0; i < nums.length; i++) {
      result = result ^ nums[i];
    }
    return result;
  }
}
