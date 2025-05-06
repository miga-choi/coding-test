import java.util.Arrays;
import java.util.Stack;

class _132Pattern {
    public boolean find132pattern(int[] nums) {
        Stack<Integer> stack = new Stack<Integer>();
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
    // Solution 1: Naive O(n^3) solution
    public boolean solution1(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                for (int k = j + 1; k < nums.length; k++) {
                    if (nums[i] < nums[k] && nums[k] < nums[j])
                        return true;
                }
            }
        }
        return false;
    }

    // Solution 2: Improved O(n^2) solution
    public boolean solution2(int[] nums) {
        for (int j = 0, min = Integer.MAX_VALUE; j < nums.length; j++) {
            min = Math.min(nums[j], min);
            if (min == nums[j])
                continue;

            for (int k = nums.length - 1; k > j; k--) {
                if (min < nums[k] && nums[k] < nums[j])
                    return true;
            }
        }
        return false;
    }

    // Solution 3: Optimized O(n) solution
    public boolean solution3(int[] nums) {
        int[] arr = Arrays.copyOf(nums, nums.length);

        for (int i = 1; i < nums.length; i++) {
            arr[i] = Math.min(nums[i - 1], arr[i - 1]);
        }

        for (int j = nums.length - 1, top = nums.length; j >= 0; j--) {
            if (nums[j] <= arr[j])
                continue;
            while (top < nums.length && arr[top] <= arr[j])
                top++;
            if (top < nums.length && nums[j] > arr[top])
                return true;
            arr[--top] = nums[j];
        }

        return false;
    }

    // Solution 4: One-pass O(n) solution
    public boolean solution4(int[] nums) {
        int n = nums.length, top = n, third = Integer.MIN_VALUE;

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < third)
                return true;
            while (top < n && nums[i] > nums[top])
                third = nums[top++];
            nums[--top] = nums[i];
        }

        return false;
    }
}
