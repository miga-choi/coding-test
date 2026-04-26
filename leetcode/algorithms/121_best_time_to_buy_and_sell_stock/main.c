#include <limits.h>

/**
 * Greedy
 * 
 * Complexities:
 *   N - `pricesSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    int minPrice = 100000;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }

        int diff = prices[i] - minPrice;
        if (diff > profit) {
            profit = diff;
        }
    }

    return profit;
}


// Solution
/**
 * Greedy
 * 
 * Complexities:
 *   N - `pricesSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2) {
        return 0;
    }

    int min_price = INT_MAX;
    int max_profit = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < min_price) {
            min_price = prices[i];
        } else if (prices[i] - min_price > max_profit) {
            max_profit = prices[i] - min_price;
        }
    }

    return max_profit;
}
