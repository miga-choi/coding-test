import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class FindAllNumbersDisappearedInAnArray {
    /**
     * Auxiliary Array
     *
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> result = new ArrayList<>();
        int length = nums.length;
        nums = Arrays.stream(nums).distinct().sorted().toArray();
        int count = 0;

        for (int i = 1; i <= length; i++) {
            if (count >= nums.length - 1) {
                result.add(i);
                continue;
            }
            if (nums[count] != i) {
                result.add(i);
            } else {
                count++;
            }
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Auxiliary Array
     *
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    public List<Integer> solution1(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            int idx = Math.abs(nums[i]) - 1;
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }
        }

        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                result.add(i + 1);
            }
        }

        return result;
    }

    /**
     * Solution 2
     * 
     * Boolean Array
     *
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    public List<Integer> solution2(int[] nums) {
        boolean[] seen = new boolean[nums.length + 1];
        for (int v : nums) {
            seen[v] = true;
        }

        List<Integer> result = new ArrayList<>();
        for (int i = 1; i <= nums.length; i++) {
            if (!seen[i]) {
                result.add(i);
            }
        }

        return result;
    }

    /**
     * Solution 3
     *
     * Cyclic Sort
     *
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public List<Integer> solution3(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            while (nums[i] != nums[nums[i] - 1]) {
                int tmp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = tmp;
            }
        }

        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != i + 1) {
                result.add(i + 1);
            }
        }

        return result;
    }
}
