import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class IntersectionOfTwoArrays {
    /**
     * Complexities:
     *   N - The size of `nums1`
     *   M - The size of `nums2`
     *   - Time Complexity: O(N * M)
     *   - Space Complexity: O(N)
     */
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> result = new HashSet<>();

        for (int num1 : nums1) {
            for (int num2 : nums2) {
                if (num1 == num2) {
                    result.add(num1);
                }
            }
        }

        return result.stream().mapToInt(Integer::intValue).toArray();
    }


    // Solution
    /**
     * Solution 1
     *
     * HashSet
     *
     * Complexities:
     *   N - The size of `nums1`
     *   M - The size of `nums2`
     *   - Time Complexity: O(N + M)
     *   - Space Complexity: O(N + M)
     */
    public int[] solution1(int[] nums1, int[] nums2) {
        Set<Integer> set = new HashSet<>();
        for (int x : nums1) {
            set.add(x);
        }

        List<Integer> result = new ArrayList<>();
        for (int x : nums2) {
            if (set.remove(x)) {
                result.add(x);
            }
        }

        int[] ans = new int[result.size()];
        for (int i = 0; i < ans.length; i++) {
            ans[i] = result.get(i);
        }

        return ans;
    }

    /**
     * Solution 2
     *
     * Sort + Two pointers
     *
     * Complexities:
     *   N - The size of `nums1`
     *   M - The size of `nums2`
     *   - Time Complexity: O(N * logᴺ + M * logᴹ)
     *   - Space Complexity: O(1)
     */
    public int[] solution2(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        int i = 0, j = 0, k = 0;
        int[] tmp = new int[Math.min(nums1.length, nums2.length)];

        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                if (k == 0 || tmp[k - 1] != nums1[i])
                    tmp[k++] = nums1[i];
                i++;
                j++;
            }
        }

        return Arrays.copyOf(tmp, k);
    }

    /**
     * Solution 3
     *
     * Constraints
     *
     * Complexities:
     *   N - The size of `nums1`
     *   M - The size of `nums2`
     *   - Time Complexity: O(N + M)
     *   - Space Complexity: O(1)
     */
    public int[] solution3(int[] nums1, int[] nums2) {
        boolean[] inFirst = new boolean[1001];
        for (int x : nums1) {
            inFirst[x] = true;
        }

        int[] tmp = new int[1001];
        int k = 0;
        for (int x : nums2) {
            if (inFirst[x]) {
                tmp[k++] = x;
                inFirst[x] = false;
            }
        }

        return Arrays.copyOf(tmp, k);
    }
}
