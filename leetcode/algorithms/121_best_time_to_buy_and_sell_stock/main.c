#include <limits.h>

/**
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 */
int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    int minPrice = 100000;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < min) {
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
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 */
int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int solution(int* prices, int pricesSize) {
    if (pricesSize < 2) {
        return 0;
    }

    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < pricesSize; i++) {
        int currentPrice = prices[i];

        minPrice = min(minPrice, currentPrice);

        int potentialProfit = currentPrice - minPrice;
        maxProfit = max(maxProfit, potentialProfit);
    }

    return maxProfit;
}
