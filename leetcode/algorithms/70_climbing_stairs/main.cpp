#include <unordered_map>
using namespace std;

class ClimbingStairs
{
public:
    int climbStairs(int n)
    {
        if (n < 2)
        {
            return 1;
        }

        int dp[n];
        dp[0] = 1;
        dp[1] = 2;

        for (int i = 2; i < n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n - 1];
    }


    // Best Solution
    // Best Solution 1: Fibonacci sequence
    int bestSolution1(int n)
    {
        // base cases
        if (n <= 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }

        int one_step_before = 2;
        int two_steps_before = 1;
        int all_ways = 0;

        for (int i = 2; i < n; i++)
        {
            all_ways = one_step_before + two_steps_before;
            two_steps_before = one_step_before;
            one_step_before = all_ways;
        }
        return all_ways;
    }

    // Best Solution 2: Recursion
    int bestSolution2(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        return bestSolution2(n - 1) + bestSolution2(n - 2);
    }

    // Best Solution 3: Memoization
    int bestSolution3(int n)
    {
        unordered_map<int, int> memo;
        return bestSolution3(n, memo);
    }

    int bestSolution3(int n, unordered_map<int, int> &memo)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        if (memo.find(n) == memo.end())
        {
            memo[n] = bestSolution3(n - 1, memo) + bestSolution3(n - 2, memo);
        }
        return memo[n];
    }

    // Best Solution 4: Tabulation
    int bestSolution4(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }

        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // Best Solution 5: Space Optimization
    int bestSolution5(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++)
        {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
};