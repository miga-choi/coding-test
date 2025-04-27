class IntersectionOfTwoArrays {
  List<int> intersection(List<int> nums1, List<int> nums2) {
    Set<int> numsSet = Set<int>();

    for (int num1 in nums1) {
      for (int num2 in nums2) {
        if (num1 == num2) {
          numsSet.add(num1);
        }
      }
    }

    return numsSet.toList();
  }


  // Solution
  List<int> solution(List<int> nums1, List<int> nums2) {
    Set<int> newNums1 = nums1.toSet();
    Set<int> newNum2 = nums2.toSet();
    return newNums1.intersection(newNum2).toList();
  }
}
