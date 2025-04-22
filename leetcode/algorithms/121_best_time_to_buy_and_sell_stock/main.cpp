#include <limits.h>
#include <vector>
using namespace std;

class BestTimeToBuyAndSellStock {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 10000;
        int price = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            if (prices[i] - minPrice > price) {
                price = prices[i] - minPrice;
            }
        }
        return price;
    }


    // Solution
    int solution(vector<int>& prices) {
        int lsf = INT_MAX;
        int op = 0;
        int pist = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < lsf) {
                lsf = prices[i];
            }
            pist = prices[i] - lsf;
            if (op < pist) {
                op = pist;
            }
        }
        return op;
    }
};
