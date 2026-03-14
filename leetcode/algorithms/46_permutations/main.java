import java.util.ArrayList;
import java.util.List;

class Permutations {
    /**
     * Backtracking
     * 
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N * N!)
     *   - Space Complexity: O(N)
     */
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();

        backtracking(result, new ArrayList<>(), nums, new boolean[nums.length]);

        return result;
    }

    private void backtracking(List<List<Integer>> result, List<Integer> current, int[] nums, boolean[] used) {
        if (current.size() == nums.length) {
            result.add(new ArrayList<>(current));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (used[i]) {
                continue;
            }

            used[i] = true;
            current.add(nums[i]);

            backtracking(result, current, nums, used);

            current.remove(current.size() - 1);
            used[i] = false;
        }
    }


    // Solution
    /**
     * Backtracking
     * 
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N * N!)
     *   - Space Complexity: O(N)
     */
    public List<List<Integer>> solution(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();

        backtrack(result, new ArrayList<>(), nums, new boolean[nums.length]);

        return result;
    }

    private void backtrack(List<List<Integer>> result, List<Integer> current, int[] nums, boolean[] used) {
        if (current.size() == nums.length) {
            result.add(new ArrayList<>(current));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (used[i]) {
                continue;
            }

            used[i] = true;
            current.add(nums[i]);

            backtrack(result, current, nums, used);

            current.remove(current.size() - 1);
            used[i] = false;
        }
    }
}
