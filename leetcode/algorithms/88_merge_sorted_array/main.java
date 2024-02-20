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
  // Best Solution 1: STL
  public void bestSolution1(int[] nums1, int m, int[] nums2, int n) {
    for (int j = 0, i = m; j < n; j++) {
      nums1[i] = nums2[j];
      i++;
    }
    Arrays.sort(nums1);
  }

  // Best Solution 2: Two Pointer
  public void bestSolution2(int[] nums1, int m, int[] nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (j >= 0) {
      if (i >= 0 && nums1[i] > nums2[j]) {
        nums1[k--] = nums1[i--];
      } else {
        nums1[k--] = nums2[j--];
      }
    }
  }

  // Best Solution 3:
  public void bestSolution3(int[] nums1, int m, int[] nums2, int n) {
    int tail1 = m - 1, tail2 = n - 1, finished = m + n - 1;
    while (tail1 >= 0 && tail2 >= 0) {
      nums1[finished--] = (nums1[tail1] > nums2[tail2]) ? nums1[tail1--] : nums2[tail2--];
    }

    while (tail2 >= 0) { // only need to combine with remaining nums2, if any
      nums1[finished--] = nums2[tail2--];
    }
  }

  // Best Solution 4:
  public void bestSolution4(int[] nums1, int m, int[] nums2, int n) {
    // variables to work as pointers
    int i = m - 1; // will point at m-1 index of nums1 array
    int j = n - 1; // will point at n-1 index of nums2 array
    int k = nums1.length - 1; // will point at the last position of the nums1 array

    // Now traversing the nums2 array
    while (j >= 0) {
      // If element at i index of nums1 > element at j index of nums2
      // then it is largest among two arrays and will be stored at k position of nums1
      // using i>=0 to make sure we have elements to compare in nums1 array
      if (i >= 0 && nums1[i] > nums2[j]) {
        nums1[k] = nums1[i];
        k--;
        i--; // updating pointer for further comparisons
      } else {
        // element at j index of nums2 array is greater than the element at i index of
        // nums1 array
        // or there is no element left to compare with the nums1 array
        // and we just have to push the elements of nums2 array in the nums1 array.
        nums1[k] = nums2[j];
        k--;
        j--; // updating pointer for further comparisons
      }
    }
  }
}
