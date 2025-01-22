class NextGreaterElementI {
  List<int> nextGreaterElement(List<int> nums1, List<int> nums2) {
    final List<int> result = List<int>.filled(nums1.length, -1);
    final List<int> numsBool = List<int>.filled(nums1.length, 0);

    for (int i = 0; i < nums1.length; i++) {
      for (int j = 0; j < nums2.length; j++) {
        if (numsBool[i] == 1 && nums2[j] > nums1[i]) {
          result[i] = nums2[j];
          numsBool[i] = 0;
        } else if (nums1[i] == nums2[j]) {
          numsBool[i] = 1;
        }
      }
    }

    return result;
  }

  // Solution
  List<int> solution(List<int> nums1, List<int> nums2) {
    List<int> store = [];

    for (int num in nums1) {
      int index = nums2.indexOf(num);
      int number = nums2.sublist(index + 1).firstWhere(
            (int element) => element > num,
            orElse: () => -1,
          );
      store.add(number);
    }

    return store;
  }
}
