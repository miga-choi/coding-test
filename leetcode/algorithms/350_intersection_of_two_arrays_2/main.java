import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class IntersectionOfTwoArraysII {
    /**
     * Complexities:
     *   N - The size of `nums1`
     *   M - The size of `nums2`
     *   - Time Complexity: O(N * M)
     *   - Space Complexity: O(N + M)
     */
    public int[] intersect(int[] nums1, int[] nums2) {
        List<Integer> result = new ArrayList<>();
        Map<Integer, Integer> numsMap = new HashMap<>();

        for (Integer num1 : nums1) {
            if (numsMap.get(num1) == null) {
                numsMap.put(num1, 1);
            } else {
                numsMap.put(num1, numsMap.get(num1) + 1);
            }
        }

        for (Integer num2 : nums2) {
            if (numsMap.get(num2) != null && numsMap.get(num2) > 0) {
                result.add(num2);
                numsMap.put(num2, numsMap.get(num2) - 1);
            }
        }

        return result.stream().mapToInt(Integer::intValue).toArray();
    }


    // Solution
    /**
     * Solution 1
     *
     * Map
     *
     * Complexities:
     *   N - The size of `nums1`
     *   M - The size of `nums2`
     *   - Time Complexity: O(N + M)
     *   - Space Complexity: O(min(N, M))
     */
    public int[] solution1(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) {
            return intersect(nums2, nums1);
        }

        Map<Integer, Integer> count = new HashMap<>();
        for (int x : nums1) {
            count.merge(x, 1, Integer::sum);
        }

        int[] tmp = new int[nums1.length];
        int k = 0;
        for (int x : nums2) {
            int c = count.getOrDefault(x, 0);
            if (c > 0) {
                tmp[k++] = x;
                count.put(x, c - 1);
            }
        }

        return Arrays.copyOf(tmp, k);
    }

    /**
     * Solution 2
     *
     * Sorting + Two Pointers
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
        int[] count = new int[1001];
        for (int x : nums1) {
            count[x]++;
        }

        int[] tmp = new int[Math.min(nums1.length, nums2.length)];
        int k = 0;
        for (int x : nums2) {
            if (count[x] > 0) {
                tmp[k++] = x;
                count[x]--;
            }
        }

        return Arrays.copyOf(tmp, k);
    }
}
