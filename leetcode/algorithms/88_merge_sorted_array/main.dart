class MergeSortedArray {
  void merge(List<int> nums1, int m, List<int> nums2, int n) {
    nums1.removeRange(m, m + n);
    int index = 0;
    while (nums2.isNotEmpty) {
      if (index >= nums1.length) {
        nums1.addAll(nums2);
        break;
      }
      if (nums1[index] >= nums2.first) {
        nums1.insert(index, nums2.removeAt(0));
      }
      index++;
    }
  }


  // Solution
  void solution(List<int> nums1, int m, List<int> nums2, int n) {
    int i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0) {
      if (nums1[i] >= nums2[j]) {
        nums1[i + j + 1] = nums1[i];
        i--;
      } else {
        nums1[i + j + 1] = nums2[j];
        j--;
      }
    }
    while (j >= 0) {
      nums1[j] = nums2[j];
      j--;
    }
  }
}
