public class MergeSortedArray {
    public void Merge(int[] nums1, int m, int[] nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
        Array.Sort(nums1, 0, nums1.Length);
    }


    // Solution
    // Solution 1:
    public void solution1(int[] nums1, int m, int[] nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int i = m + n - 1;

        while (p2 >= 0) {
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[i--] = nums1[p1--];
            } else {
                nums1[i--] = nums2[p2--];
            }
        }
    }

    // Solution 2:
    public void solution2(int[] nums1, int m, int[] nums2, int n) {
        if (n == 0) {
            return;
        }

        int len1 = nums1.Length;
        int end_idx = len1 - 1;

        while (n > 0 && m > 0) {
            if (nums2[n - 1] >= nums1[m - 1]) {
                nums1[end_idx] = nums2[n - 1];
                n--;
            } else {
                nums1[end_idx] = nums1[m - 1];
                m--;
            }
            end_idx--;
        }
        while (n > 0) {
            nums1[end_idx] = nums2[n - 1];
            n--;
            end_idx--;
        }
    }

    // Solution 3:
    public void solution3(int[] nums1, int m, int[] nums2, int n) {
        Array.Copy(nums2, 0, nums1, m, n);
        Array.Sort(nums1);
    }

    // Solution 4:
    public void solution4(int[] nums1, int m, int[] nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
        Array.Sort(nums1);
    }
}
