class RemoveElement {
  int removeElement(List<int> nums, int val) {
    nums.removeWhere((e) => e == val);
    return 0;
  }


  // Solution
  int solution(List<int> nums, int val) {
    int cnt = 0;
    for (int i = 0; i < nums.length; i++) {
      if (nums[i] != val) {
        nums[cnt] = nums[i];
        cnt++;
      }
    }
    return cnt;
  }
}
