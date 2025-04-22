class MoveZeroes {
  void moveZeroes(List<int> nums) {
    int zeroCount = 0;
    for (int num in nums) {
      if (num == 0) {
        zeroCount++;
      }
    }
    nums.removeWhere((int num) => num == 0);
    nums.addAll(List<int>.filled(zeroCount, 0));
  }


  // Solution
  void solution(List<int> nums) {
    List<int> testValues = [];
    nums.forEach((value) => testValues.add(value));
    testValues.retainWhere((value) => value == 0);
    nums.removeWhere((value) => value == 0);
    nums.addAll(testValues);
  }
}
