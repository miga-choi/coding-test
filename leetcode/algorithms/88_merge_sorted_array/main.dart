class MergeSortedArray {
  /**
   * Three Pointers: from end to begin
   * - Time Complexity: O(M+N)
   * - Time Complexity: O(1)
   */
  void merge(List<int> nums1, int m, List<int> nums2, int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    int p = m + n - 1;

    while (p2 >= 0) {
      if (p1 >= 0 && nums1[p1] > nums2[p2]) {
        nums1[p] = nums1[p1];
        p1--;
      } else {
        nums1[p] = nums2[p2];
        p2--;
      }
      p--;
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
