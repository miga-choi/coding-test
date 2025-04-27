/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = NumArray(nums);
 * int param1 = obj.sumRange(left,right);
 */

class NumArray {
  late final List<int> _numArray;

  NumArray(List<int> nums) {
    _numArray = nums;
  }

  int sumRange(int left, int right) {
    int sum = 0;
    for (var i = left; i <= right; i++) {
      sum += _numArray[i];
    }
    return sum;
  }
}


// Solution
class Solution {
  List<int> arr = [];

  Solution(List<int> nums) {
    List<int> sums = [];
    var currentSum = 0;
    for (var num in nums) {
      currentSum += num;
      sums.add(currentSum);
    }
    arr = sums;
  }

  int sumRange(int left, int right) {
    if (left == 0) {
      return arr[right];
    }
    return arr[right] - arr[left - 1];
  }
}
