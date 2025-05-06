class MaxConsecutiveOnes {
  int findMaxConsecutiveOnes(List<int> nums) {
    int max = 0;
    int current = 0;

    for (int num in nums) {
      if (num > 0) {
        current++;
        if (current > max) {
          max = current;
        }
      } else {
        current = 0;
      }
    }

    return max;
  }


  // Solution
  int solution(List<int> nums) {
    int count = 0, flag = 0;

    for (int i = 0; i < nums.length; i++) {
      if (nums[i] == 1) {
        count++;
        if (count > flag) {
          flag = count;
        }
      } else {
        count = 0;
      }
    }

    return flag;
  }
}
