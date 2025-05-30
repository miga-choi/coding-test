public class SearchInsertPosition {
    public int SearchInsert(int[] nums, int target) {
        int left = 0;
        int right = nums.Length - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (target > nums[mid]) {
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                return mid;
            }
        }

        return left;
    }


    // Solution
    // Solution 1
    public int solution1(int[] nums, int target) {
        int left = 0, right = nums.Length - 1, mid;
        while (left <= right) {
            mid = (right + left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return left;
    }

    // Solution 2
    public int solution2(int[] nums, int target) {
        var index = Array.BinarySearch(nums, target);
        return index >= 0 ? index : ~index;
    }

    // Solution 3
    public int solution3(int[] nums, int target) {
        for (int i = 0; i < nums.Length; i++) {
            if (target == nums[i] || nums[i] > target) {
                return i;
            }
        }
        return nums.Length;
    }
}
