#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

class BestTimeToBuyAndSellStock {
public:
    /**
     * Greedy
     *
     * Complexities:
     *   N - Size of `prices`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
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
     * Greedy
     *
     * Complexities:
     *   N - Size of `prices`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution(vector<int>& prices) {
        int min_price = INT_MAX; 
        int max_profit = 0;

        for (int price : prices) {
            min_price = min(min_price, price);
            
            max_profit = max(max_profit, price - min_price);
        }

        return max_profit;
    }
};
