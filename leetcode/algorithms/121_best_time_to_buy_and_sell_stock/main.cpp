#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

class BestTimeToBuyAndSellStock {
public:
    /**
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    int maxProfit(vector<int>& prices) {
        int minPrice = 100000;
        int profit = 0;

        for (int& price : prices) {
            if (price < minPrice) {
                minPrice = price;
            }

            int diff = price - minPrice;
            if (diff > profit) {
                profit = diff;
            }
        }

        return profit;
    }


    // Solution
    /**
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }

        int minPrice = numeric_limits<int>::max();
        int maxProfit = 0;

        for (int currentPrice : prices) {
            minPrice = min(minPrice, currentPrice);

            int potentialProfit = currentPrice - minPrice;
            maxProfit = max(maxProfit, potentialProfit);
        }

        return maxProfit;
    }
};
