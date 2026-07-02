import java.util.ArrayList;
import java.util.List;

class SummaryRanges {
    /**
     * Two Pointers
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public List<String> summaryRanges(int[] nums) {
        List<String> result = new ArrayList<>();

        if (nums.length > 0) {
            int num = nums[0];
            List<Integer> numArray = new ArrayList<>();
            numArray.add(num);

            for (int i = 1; i < nums.length; i++) {
                if (nums[i] - num == 1) {
                    numArray.add(nums[i]);
                } else {
                    if (numArray.size() > 1) {
                        result.add(String.valueOf(numArray.get(0)) + "->"
                                + String.valueOf(numArray.get(numArray.size() - 1)));
                    } else {
                        result.add(String.valueOf(numArray.get(0)));
                    }
                    numArray = new ArrayList<Integer>();
                    numArray.add(nums[i]);
                }
                num = nums[i];
            }

            if (numArray.size() > 0) {
                if (numArray.size() > 1) {
                    result.add(String.valueOf(numArray.get(0)) + "->"
                            + String.valueOf(numArray.get(numArray.size() - 1)));
                } else {
                    result.add(String.valueOf(numArray.get(0)));
                }
            }
        }

        return result;
    }


    // Solution
    /**
     * Two Pointers
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public List<String> solution(int[] nums) {
        List<String> result = new ArrayList<>();

        if (nums == null || nums.length == 0) {
            return result;
        }

        int n = nums.length;
        int i = 0;

        while (i < n) {
            int start = nums[i];

            while (i + 1 < n && nums[i] + 1 == nums[i + 1]) {
                i++;
            }

            if (start == nums[i]) {
                result.add(String.valueOf(start));
            } else {
                result.add(start + "->" + nums[i]);
            }

            i++;
        }

        return result;
    }
}
