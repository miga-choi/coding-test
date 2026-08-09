import java.util.ArrayList;
import java.util.List;

class NumArray {
    /**
     * Complexities:
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    List<Integer> numArray = new ArrayList<Integer>();

    public NumArray(int[] nums) {
        for (int num : nums) {
            numArray.add(num);
        }
    }

    public int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; i++) {
            sum += numArray.get(i);
        }
        return sum;
    }


    // Solution
    /**
     * Complexities:
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    class Solution {
        private final int[] prefix;

        public Solution(int[] nums) {
            prefix = new int[nums.length + 1];
            for (int i = 0; i < nums.length; i++) {
                prefix[i + 1] = prefix[i] + nums[i];
            }
        }

        public int sumRange(int left, int right) {
            return prefix[right + 1] - prefix[left];
        }
    }
}
