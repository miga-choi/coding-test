#include <utility>
#include <vector>
using namespace std;

class Subsets {
public:
    void backtracking(int start, const vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);

        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]);

            backtracking(i + 1, nums, current, result);

            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        backtracking(0, nums, current, result);

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
    void backtrack(int start, const vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);

        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]);
            
            backtrack(i + 1, nums, current, result);
            
            current.pop_back();
        }
    }

    vector<vector<int>> solution1(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        
        backtrack(0, nums, current, result);
        
        return result;
    }


    /**
     * Solution 2
     * 
     * Bitmasking
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N * 2ᴺ)
     *   - Space Complexity: O(N)
     */
    vector<vector<int>> solution2(vector<int>& nums) {
        int n = nums.size();
        int subsetCount = 1 << n;
        vector<vector<int>> result;
        
        for (int i = 0; i < subsetCount; ++i) {
            vector<int> current;
            
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    current.push_back(nums[j]);
                }
            }

            result.push_back(current);
        }
        
        return result;
    }
};
