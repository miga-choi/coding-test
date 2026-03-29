#include <vector>
using namespace std;

class UniquePaths {
public:
    /**
     * DP
     *
     * Complexities:
     *   M - `m`
     *   N - `n`
     *   - Time Complexity: O(M * N)
     *   - Space Complexity: O(M * N)
     */
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }


    // Solution
    /**
     * Solution 1
     * 
     * DP
     *
     * Complexities:
     *   M - `m`
     *   N - `n`
     *   - Time Complexity: O(M * N)
     *   - Space Complexity: O(N)
     */
    int solution1(int m, int n) {
        vector<int> dp(n, 1);

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }

        return dp[n - 1];
    }

    /**
     * Solution 2
     * 
     * Combinatorics
     * 
     * Complexities:
     *   M - `m`
     *   N - `n`
     *   - Time Complexity: O(min(M, N))
     *   - Space Complexity: O(1)
     */
    int solution2(int m, int n) {
        int total_moves = m + n - 2;
        int k = std::min(m - 1, n - 1); 
        
        long long result = 1;

        for (int i = 1; i <= k; ++i) {
            result = result * (total_moves - i + 1) / i;
        }

        return static_cast<int>(result);
    }
};
