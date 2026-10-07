import java.util.Arrays;
import java.util.TreeSet;

class ThirdMaximumNumber {
    /**
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int thirdMax(int[] nums) {
        nums = Arrays.stream(nums).distinct().toArray();

        if (nums.length > 2) {
            for (int i = 0; i < 2; i++) {
                int maxNum = Arrays.stream(nums).max().getAsInt();
                nums = Arrays.stream(nums).filter(value -> value < maxNum).toArray();
            }
        }

        return Arrays.stream(nums).max().getAsInt();
    }


    // Solution
    /**
     * Solution 1
     * 
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int solution1(int[] nums) {
        long first = Long.MIN_VALUE, second = Long.MIN_VALUE, third = Long.MIN_VALUE;

        for (int n : nums) {
            if (n == first || n == second || n == third) {
                continue;
            }

            if (n > first) {
                third = second;
                second = first;
                first = n;
            } else if (n > second) {
                third = second;
                second = n;
            } else if (n > third) {
                third = n;
            }
        }

        return third == Long.MIN_VALUE ? (int) first : (int) third;
    }

    /**
     * Solution 2
     * 
     * TreeSet
     * 
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int solution2(int[] nums) {
        TreeSet<Integer> set = new TreeSet<>();

        for (int n : nums) {
            set.add(n);

            if (set.size() > 3) {
                set.pollFirst();
            }
        }

        return set.size() == 3 ? set.first() : set.last();
    }

    /**
     * Solution 3
     * 
     * Sorting
     * 
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N * logᴺ)
     *   - Space Complexity: O(1)
     */
    public int solution3(int[] nums) {
        Arrays.sort(nums);

        int count = 1;
        for (int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] != nums[i + 1] && ++count == 3) {
                return nums[i];
            }
        }

        return nums[nums.length - 1];
    }
}
