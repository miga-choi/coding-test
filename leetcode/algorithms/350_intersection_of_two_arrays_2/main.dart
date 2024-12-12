class IntersectionOfTwoArraysII {
  List<int> intersect(List<int> nums1, List<int> nums2) {
    List<int> result = List<int>.empty(growable: true);
    for (int i = 0; i < nums1.length; i++) {
      for (int j = 0; j < nums2.length; j++) {
        if (nums1[i] != -1 && nums1[i] == nums2[j]) {
          result.add(nums1[i]);
          nums1[i] = -1;
          nums2[j] = -1;
        }
      }
    }
    return result;
  }

  // Best Solution
  List<int> bestSolution(List<int> nums1, List<int> nums2) {
    nums1.sort();
    nums2.sort();
    List<int> res = [];
    int i = 0, j = 0;
    while (i < nums1.length && j < nums2.length) {
      if (nums1[i] == nums2[j]) {
        res.add(nums1[i]);
        i++;
        j++;
      } else if (nums1[i] > nums2[j])
        j++;
      else
        i++;
    }
    return res;
  }
}
