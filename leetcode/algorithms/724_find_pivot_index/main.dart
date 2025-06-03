class FindPivotIndex {
  int pivotIndex(List<int> nums) {
    int leftSum = 0;
    int rightSum = nums.reduce((int value, int element) => value + element);

    for (var i = 0; i < nums.length; i++) {
      rightSum -= nums[i];

      if (leftSum == rightSum) {
        return i;
      }

      leftSum += nums[i];
    }

    return -1;
  }


  // Solution
  int solution(List<int> nums) {
    int leftSum = 0;
    int rightSum = nums.reduce((a, b) => a + b);
    int ind = 0;

    while (ind < nums.length) {
      leftSum = leftSum + nums[ind];

      if (leftSum == rightSum) {
        return ind;
      }

      rightSum = rightSum - nums[ind];

      ind++;
    }

    return -1;
  }
}
