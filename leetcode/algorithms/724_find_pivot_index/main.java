import java.util.Arrays;

class FindPivotIndex {
    public int pivotIndex(int[] nums) {
        int leftSum = 0;
        int rightSum = Arrays.stream(nums).sum();

        for (int i = 0; i < nums.length; i++) {
            rightSum -= nums[i];

            if (leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }


    // Solution
    public int solution(int[] nums) {
        // Initialize total sum of the given array
        int totalSum = 0;

        // Initialize 'leftsum' as sum of first i numbers,
        // not including nums[i]
        int leftsum = 0;

        // Traverse the elements and add them to store the totalSum
        for (int ele : nums) {
            totalSum += ele;
        }

        // Again traverse all the elements through the for loop
        // and store the sum of i numbers from left to right
        for (int i = 0; i < nums.length; leftsum += nums[i++]) {
            // sum to the left == leftsum.
            // sum to the right === totalSum - leftsum - nums[i]
            // check if leftsum == totalSum - leftsum - nums[i]
            if (leftsum * 2 == totalSum - nums[i]) {
                // Return the pivot index
                return i;
            }
        }

        // If there is no index that satisfies the conditions
        // in the problem statement
        return -1;
    }
}
