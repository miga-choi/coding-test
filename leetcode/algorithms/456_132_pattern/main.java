import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Stack;

class _132Pattern {
    /**
     * Monotonic Stack
     *
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    public boolean find132pattern(int[] nums) {
        Stack<Integer> stack = new Stack<>();
        int third = -Double.valueOf(Math.pow(10, 9)).intValue();

        for (int i = nums.length - 1; i >= 0; i--) {
            if (nums[i] < third) {
                return true;
            }

            while (!stack.empty() && stack.lastElement() < nums[i]) {
                third = stack.pop();
            }

            stack.add(nums[i]);
        }

        return false;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Monotonic Stack
     *
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    public boolean solution1(int[] nums) {
        Deque<Integer> stack = new ArrayDeque<>();
        int third = Integer.MIN_VALUE;

        for (int i = nums.length - 1; i >= 0; i--) {
            if (nums[i] < third) {
                return true;
            }

            while (!stack.isEmpty() && stack.peek() < nums[i]) {
                third = stack.pop();
            }

            stack.push(nums[i]);
        }

        return false;
    }

    /**
     * Solution 2
     *
     * Prefix Minimum + Monotonic Stack
     *
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    public boolean solution2(int[] nums) {
        int n = nums.length;
        if (n < 3) {
            return false;
        }

        int[] minLeft = new int[n];
        minLeft[0] = Integer.MAX_VALUE;

        for (int j = 1; j < n; j++) {
            minLeft[j] = Math.min(minLeft[j - 1], nums[j - 1]);
        }

        Deque<Integer> stack = new ArrayDeque<>();

        for (int j = n - 1; j >= 0; j--) {
            if (minLeft[j] < nums[j]) {
                while (!stack.isEmpty() && stack.peek() <= minLeft[j]) {
                    stack.pop();
                }

                if (!stack.isEmpty() && stack.peek() < nums[j]) {
                    return true;
                }
            }

            stack.push(nums[j]);
        }

        return false;
    }

    /**
     * Solution 3
     *
     * Brute Force
     *
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N³)
     *   - Space Complexity: O(1)
     */
    public boolean solution3(int[] nums) {
        for (int j = 1; j < nums.length - 1; j++) {
            for (int i = 0; i < j; i++) {
                if (nums[i] >= nums[j]) {
                    continue;
                }

                for (int k = j + 1; k < nums.length; k++) {
                    if (nums[i] < nums[k] && nums[k] < nums[j]) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
}
