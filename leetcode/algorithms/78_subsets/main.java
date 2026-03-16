import java.util.ArrayList;
import java.util.List;

class Subsets {
    public void backtracking(int start, int[] nums, List<Integer> current, List<List<Integer>> result) {
        result.add(new ArrayList<>(current));

        for (int i = start; i < nums.length; i++) {
            current.add(nums[i]);

            backtracking(i + 1, nums, current, result);

            current.remove(current.size() - 1);
        }
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();

        backtracking(0, nums, new ArrayList<>(), result);

        return result;
    }


    // Solution
    /**
     * Solution 1
     *
     * Backtracking
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N * 2ᴺ)
     *   - Space Complexity: O(N)
     */
    public List<List<Integer>> solution(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();

        backtrack(result, new ArrayList<>(), nums, 0);

        return result;
    }

    private void backtrack(List<List<Integer>> result, List<Integer> current, int[] nums, int start) {
        result.add(new ArrayList<>(current));

        for (int i = start; i < nums.length; i++) {
            current.add(nums[i]);

            backtrack(result, current, nums, i + 1);

            current.remove(current.size() - 1);
        }
    }
}
