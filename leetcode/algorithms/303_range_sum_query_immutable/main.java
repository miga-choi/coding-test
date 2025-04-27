import java.util.ArrayList;
import java.util.List;

class NumArray {
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
    class Solution {
        int[] prefixSum;

        public Solution(int[] nums) {
            if (nums == null) {
                throw new IllegalArgumentException("Input is null");
            }

            prefixSum = new int[nums.length + 1];

            for (int i = 1; i <= nums.length; i++) {
                prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
            }
        }

        public int sumRange(int left, int right) {
            if (left < 0 || right >= prefixSum.length - 1) {
                throw new IndexOutOfBoundsException("Input indices are out of bounds");
            }

            // Here both left and right are inclusive.
            // right maps to right+1 in prefixSum. left maps to left+1 in prefixSum.
            // To get the result subtract the prefixSum before left index from prefixSum at
            // right index.
            return prefixSum[right + 1] - prefixSum[left];
        }
    }
}
