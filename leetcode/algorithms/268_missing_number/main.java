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


    // Solution
    // Solution 1: XOR
    public int solution1(int[] nums) {
        int res = nums.length;
        for (int i = 0; i < nums.length; i++) {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }

    // Solution 2: SUM
    public int solution2(int[] nums) {
        int len = nums.length;
        int sum = (0 + len) * (len + 1) / 2;
        for (int i = 0; i < len; i++) {
            sum -= nums[i];
        }
        return sum;
    }

    // Solution 3: Binary Search
    public int solution3(int[] nums) {
        Arrays.sort(nums);
        int left = 0, right = nums.length, mid = (left + right) / 2;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
