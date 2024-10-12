#include <limits.h>

int maxProfit(int *prices, int pricesSize)
{
    int minPrice = 10000;
    int price = 0;
    for (int i = 0; i < pricesSize; i++)
    {
        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
        }
        if (prices[i] - minPrice > price)
        {
            price = prices[i] - minPrice;
        }
    }
    return price;
}

// Best Solution
int bestSolution(int *prices, int pricesSize)
{
    int lsf = INT_MAX; // least so far
    int op = 0;        // overall profit
    int pist = 0;      // profit if sold today

    for (int i = 0; i < pricesSize; i++)
    {
        // if we found new buy value which is more smaller then previous one
        if (prices[i] < lsf)
        {
            // update our least so far
            lsf = prices[i];
        }

        // calculating profit if sold today by, Buy - sell
        pist = prices[i] - lsf;

        // if pist is more then our previous overall profit
        if (op < pist)
        {
            // update overall profit
            op = pist;
        }
    }

    // return op
    return op;
}