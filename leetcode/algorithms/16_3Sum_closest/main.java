import java.util.Arrays;

class ThreeSumClosest {
    /**
     * Sorting + Two Pointers
     *
     * Complexities:
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(1)
     */
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);

        int n = nums.length;
        int sum = nums[0] + nums[1] + nums[2];

        for (int flag = 0; flag < n - 2; flag++) {
            int left = flag + 1;
            int right = n - 1;

            while (left < right) {
                int currSum = nums[flag] + nums[left] + nums[right];

                if (Math.abs(currSum - target) < Math.abs(sum - target)) {
                    sum = currSum;
                }

                if (currSum < target) {
                    left++;
                } else if (currSum > target) {
                    right--;
                } else {
                    return currSum;
                }
            }
        }

        return sum;
    }


    // Solution
    /**
     * Sorting + Two Pointers
     *
     * Complexities:
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(1)
     */
    public int solution(int[] nums, int target) {
        Arrays.sort(nums);

        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.length - 2; i++) {
            int left = i + 1;
            int right = nums.length - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (Math.abs(target - currentSum) < Math.abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    left++;
                } else if (currentSum > target) {
                    right--;
                } else {
                    return target;
                }
            }
        }

        return closestSum;
    }
}
