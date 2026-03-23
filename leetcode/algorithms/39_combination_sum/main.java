import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class CombinationSum {
    /**
     * Backtracking
     * 
     * Complexities:
     *   N - Size of `candidates`
     *   T - Value of `target`
     *   M - Minimum value of `candidates`
     *   - Time Complexity: O(Nᵀ/ᴹ)
     *   - Space Complexity: O(T/M)
     */
    void backtracking(int[] candidates, int target, int start, List<Integer> current, List<List<Integer>> result) {
        if (target == 0) {
            result.add(new ArrayList<>(current));
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = start; i < candidates.length; i++) {
            current.add(candidates[i]);

            backtracking(candidates, target - candidates[i], i, current, result);

            current.removeLast();
        }
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> current = new ArrayList<>();

        backtracking(candidates, target, 0, current, result);

        return result;
    }


    // Solution
    /**
     * Backtracking
     * 
     * Complexities:
     *   N - Size of `candidates`
     *   T - Value of `target`
     *   M - Minimum value of `candidates`
     *   - Time Complexity: O(Nᵀ/ᴹ)
     *   - Space Complexity: O(T/M)
     */
    public List<List<Integer>> solution(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();

        Arrays.sort(candidates);

        backtrack(result, new ArrayList<>(), candidates, target, 0);

        return result;
    }

    private void backtrack(List<List<Integer>> result, List<Integer> current, int[] candidates, int remain, int start) {
        if (remain == 0) {
            result.add(new ArrayList<>(current));
            return;
        }

        for (int i = start; i < candidates.length; i++) {

            if (remain - candidates[i] < 0) {
                break;
            }

            current.add(candidates[i]);

            backtrack(result, current, candidates, remain - candidates[i], i);

            current.remove(current.size() - 1);
        }
    }
}
