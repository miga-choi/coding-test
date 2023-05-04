import java.util.Arrays;

class MergeSortedArray {

  public void merge(int[] nums1, int m, int[] nums2, int n) {
    for (int i = 0; i < nums1.length; i++) {
      if (i >= m) {
        nums1[i] = nums2[i - m];
      }
    }
    Arrays.sort(nums1);
  }

  // Best Solution
  public void bestSolution(int[] nums1, int m, int[] nums2, int n) {
    int tail1 = m - 1, tail2 = n - 1, finished = m + n - 1;
    while (tail1 >= 0 && tail2 >= 0) {
      nums1[finished--] =
        (nums1[tail1] > nums2[tail2]) ? nums1[tail1--] : nums2[tail2--];
    }

    while (tail2 >= 0) { //only need to combine with remaining nums2, if any
      nums1[finished--] = nums2[tail2--];
    }
  }
}
