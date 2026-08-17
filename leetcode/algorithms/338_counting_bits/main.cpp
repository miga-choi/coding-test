#include <bit> // std::popcount
#include <vector>
using namespace std;

class CountingBits {
public:
    /**
     * DP (Dynamic programming)
     *
     * Complexities:
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    vector<int> countBits(int n) {
        vector<int> result;

        for (int i = 0; i <= n; i++) {
            int sum = 0;
            int num = i;
            while (num != 0) {
                sum += num % 2;
                num /= 2;
            }
            result.push_back(sum);
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     * 
     * DP (Dynamic programming)
     *
     * Complexities:
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    vector<int> solution1(int n) {
        vector<int> dp(n + 1);

        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i >> 1] + (i & 1);
        }

        return dp;
    }

    /**
     * Solution 2
     * 
     * DP (Dynamic programming)
     *
     * Complexities:
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    vector<int> solution2(int n) {
        vector<int> dp(n + 1);

        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i & (i - 1)] + 1;
        }

        return dp;
    }
    
    /**
     * Solution 3
     * 
     * DP (Dynamic programming) + std::popcount
     *
     * Complexities:
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    vector<int> solution3(int n) {
        vector<int> ans(n + 1);

        for (int i = 0; i <= n; ++i) {
            ans[i] = popcount(static_cast<unsigned>(i));
        }

        return ans;
    }
};
