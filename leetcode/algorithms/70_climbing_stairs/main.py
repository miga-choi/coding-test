class Solution:
    def climbStairs(self, n: int) -> int:
        if n < 2:
            return 1

        # Fibonacci numbers
        dp = []
        dp.append(1)
        dp.append(2)

        for i in range(0, n):
            dp.append(dp[i - 1] + dp[i - 2])

        return dp[n - 1]

    # Best Solution
    # pure recursive (Can't pass the test case :does not work for big number, result time-exced limit)
    #   - The base case will be when only 1 or 2 steps left
    #   - Result time-exced limit
    def bestSolution1(self, n: int) -> int:
        def climb(n):
            if n == 1:  # only one step option is availble
                return 1
            if (
                n == 2
            ):  # two options are possible : to take two 1-stpes or to only take one 2-steps
                return 2
            return climb(n - 1) + climb(n - 2)

        return climb(n)

    # use dictionary (look-up table) to memorize repeating recursion
    #   - The memory start with the base case and recored every recurssion
    def bestSolution2(self, n: int) -> int:
        memo = {}
        memo[1] = 1
        memo[2] = 2

        def climb(n):
            if (
                n in memo
            ):  # if the recurssion already done before first take a look-up in the look-up table
                return memo[n]
            else:  # Store the recurssion function in the look-up table and reuturn the stored look-up table function
                memo[n] = climb(n - 1) + climb(n - 2)
                return memo[n]

        return climb(n)

    # Dynamic programming
    #   - store the distinct ways in a dynamic table
    def bestSolution2(self, n: int) -> int:
        def climb(n):
            # edge cases
            if n == 0:
                return 0
            if n == 1:
                return 1
            if n == 2:
                return 2
            dp = [0] * (n + 1)  # considering zero steps we need n+1 places
            dp[1] = 1
            dp[2] = 2
            for i in range(3, n + 1):
                dp[i] = dp[i - 1] + dp[i - 2]
            print(dp)
            return dp[n]

    return climb(n)
