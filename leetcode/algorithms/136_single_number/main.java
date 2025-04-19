class SingleNumber {
  public int singleNumber(int[] nums) {
    int result = 0;
    for (int num : nums) {
      result = result ^ num;
    }
    return result;
  }


  // Solution
  public int solution(int[] nums) {
    int result = 0;
    for (int i = 0; i < nums.length; i++) {
      result = result ^ nums[i];
    }
    return result;
  }
}
