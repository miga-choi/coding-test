#include <utility>
#include <vector>
using namespace std;

class Permutations {
public:
    /**
     * Backtracking
     * 
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N * N!)
     *   - Space Complexity: O(N)
     */
    void backtracking(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (size_t i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);

            backtracking(nums, start + 1, result);

            swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;

        backtracking(nums, 0, result);

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
     *   - Time Complexity: O(N * N!)
     *   - Space Complexity: O(N)
     */
    vector<vector<int>> solution1(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }

    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);

            backtrack(nums, start + 1, result);

            swap(nums[start], nums[i]);
        }
    }

    /**
     * Solution 2
     * 
     * C++ STL - `next_permutation`
     * 
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N * N!)
     *   - Space Complexity: O(N)
     */
    vector<vector<int>> solution2(vector<int>& nums) {
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());

        do {
            result.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        return result;
    }
};
