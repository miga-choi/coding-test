#include <algorithm>
#include <vector>
using namespace std;

class CoinChange {
public:
    /**
     * DP (Dynamic Programming)
     *
     * Complexities:
     *   N - `amount`
     *   M - The types of coins
     *   - Time Complexity: O(M * N)
     *   - Space Complexity: O(N)
     */
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        int dp[amount + 1];
        for (int i = 0; i <= amount; i++) {
            dp[i] = amount + 1;
        }

        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                int coin = coins[j];

                if (i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        if (dp[amount] > amount) {
            return -1;
        } else {
            return dp[amount];
        }
    }


    // Solution
    /**
     * DP (Dynamic Programming)
     *
     * Complexities:
     *   N - `amount`
     *   M - The types of coins
     *   - Time Complexity: O(M * N)
     *   - Space Complexity: O(N)
     */
    int solution(vector<int>& coins, int amount) {
        const int INF = amount + 1;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        for (int a = 1; a <= amount; ++a) {
            for (int c : coins) {
                if (c <= a) {
                    dp[a] = min(dp[a], dp[a - c] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
