#include <algorithm>
#include <vector>
using namespace std;

class CoinChange {
public:
    /**
     * DP (Dynamic Programming)
     * - Time Complexity: O(M * N)
     * - Space Complexity: O(N)
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
     * - Time Complexity: O(M * N)
     * - Space Complexity: O(N)
     */
    int solution(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        vector<long long> dp(amount + 1, amount + 1);

        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
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
};
