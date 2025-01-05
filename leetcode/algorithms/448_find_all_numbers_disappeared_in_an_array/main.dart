class FindAllNumbersDisappearedInAnArray {
  List<int> findDisappearedNumbers(List<int> nums) {
    List<int> numArray = List<int>.filled(nums.length, 0);

    for (int num in nums) {
      numArray[num - 1] = 1;
    }

    List<int> result = List<int>.empty(growable: true);

    for (int i = 1; i <= nums.length; i++) {
      if (numArray[i - 1] == 0) {
        result.add(i);
      }
    }

    return result;
  }

  // Best Solution
  List<int> bestSolution(List<int> nums) {
    Set<int> distinct = {...nums};
    int len = nums.length;
    List<int> res = [];
    for (int i = 1; i <= len; i++) {
      if (!(distinct.contains(i))) {
        res.add(i);
      }
    }
    return res;
  }
}
