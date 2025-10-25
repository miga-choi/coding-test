
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class ThreeSum {
    /**
     * Sort + Two-pointer
     * - Time Complexity: O(N²)
     * - Space Complexity: O(logᴺ)
     */
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        int numsLength = nums.length;

        for (int flag = 0; flag < numsLength - 2; flag++) {
            if (flag > 0 && nums[flag] == nums[flag - 1]) {
                continue;
            }

            int left = flag + 1;
            int right = numsLength - 1;

            while (left < right) {
                final int sum = nums[flag] + nums[left] + nums[right];

                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    result.add(Arrays.asList(nums[flag], nums[left], nums[right]));

                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }

        return result;
    }


    // Solution
    /**
     * Sort + Two-pointer
     * - Time Complexity: O(N²)
     * - Space Complexity: O(logᴺ)
     */
    public List<List<Integer>> solution(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();

        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 2; i++) {
            if (nums[i] > 0) {
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.length - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));

                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                }
            }
        }

        return result;
    }
}
