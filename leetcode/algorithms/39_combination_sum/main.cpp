#include <vector>
using namespace std;

class CombinationSum {
public:
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
    void backtracking(vector<int>& candidates, int target, int start,
                      vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]);

            backtracking(candidates, target - candidates[i], i, current, result);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

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
    void backtrack(const vector<int>& candidates, int remain, int start, 
                   vector<int>& path, vector<vector<int>>& result) {
        if (remain == 0) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > remain) {
                break; 
            }

            path.push_back(candidates[i]);
            
            backtrack(candidates, remain - candidates[i], i, path, result);
            
            path.pop_back();
        }
    }

    vector<vector<int>> solution(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, path, result);

        return result;
    }
};
