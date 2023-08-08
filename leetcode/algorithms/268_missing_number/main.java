import java.util.Arrays;

class MissingNumber {
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return nums.length;
    }


    // Best Solution
    // XOR
    public int bestSolution1(int[] nums) { // xor
        int res = nums.length;
        for (int i = 0; i < nums.length; i++) {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }

    // SUM
    public int bestSolution2(int[] nums) { // sum
        int len = nums.length;
        int sum = (0 + len) * (len + 1) / 2;
        for (int i = 0; i < len; i++)
            sum -= nums[i];
        return sum;
    }

    // Binary Search
    public int bestSolution3(int[] nums) { // binary search
        Arrays.sort(nums);
        int left = 0, right = nums.length, mid = (left + right) / 2;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] > mid)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
}