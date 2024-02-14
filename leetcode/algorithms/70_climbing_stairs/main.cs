public class ClimbingStairs
{
    public int ClimbStairs(int n)
    {
        if (n < 2)
        {
            return 1;
        }

        // Fibonacci numbers
        int[] dp = new int[n];
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
    public int bestSolution1(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // Best Solution 2: Memoization
    public int bestSolution2(int n)
    {
        int[] dp = new int[n + 1];
        Array.Fill(dp, -1);
        int k = bestSolution2Helper(n, dp);
        return k;
    }

    public int bestSolution2Helper(int n, int[] dp)
    {
        if (n <= 1)
        {
            return 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        dp[n] = bestSolution2Helper(n - 1, dp) + bestSolution2Helper(n - 2, dp);
        return dp[n];
    }

    // Best Solution 3: Tabulation
    public int bestSolution3(int n)
    {
        int[] tab = new int[n + 1];
        if (tab.Length > 0)
        {
            tab[0] = 1;
        }
        if (tab.Length > 1)
        {
            tab[1] = 1;
        }
        for (int i = 2; i < tab.Length; i++)
        {
            tab[i] = tab[i - 1] + tab[i - 2];
        }
        return tab[n];
    }

    // Best Solution 4: Space Optimization
    public int bestSolution4(int n)
    {
        if (n <= 1)
        {
            return 1;
        }
        int firstNum = 1, secondNum = 1, thirdNum = 0;
        for (int i = 2; i < n + 1; i++)
        {
            thirdNum = firstNum + secondNum;
            firstNum = secondNum;
            secondNum = thirdNum;
        }
        return thirdNum;
    }
}