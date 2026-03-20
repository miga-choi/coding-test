#include <algorithm>
#include <vector>
using namespace std;

class LongestIncreasingSubsequence {
public:
    /**
     * DP
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(N)
     */
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        for (int i = 1; i < dp.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }

        int result = 0;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i] > result) {
                result = dp[i];
            }
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     * 
     * DP
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(N)
     */
    int solution1(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, 1);
        
        int maxLength = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }

    /**
     * Solution 2
     * 
     * std::lower_bound
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N * logᴺ)
     *   - Space Complexity: O(N)
     */
    int solution2(vector<int>& nums) {
        vector<int> tails;

        for (int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);

            if (it == tails.end()) {
                tails.push_back(num);
            } else {
                *it = num;
            }
        }

        return tails.size();
    }
};
