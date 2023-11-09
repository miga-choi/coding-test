from functools import lru_cache


class Solution:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        elif n == 1:
            return 1
        else:
            return self.fib(n - 1) + self.fib(n - 2)


    # Best Solution
    # naive recursive
    def bestSolution1(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        return self.bestSolution1(n - 1) + self.bestSolution1(n - 2)

    # memoized recursive
    memo = {}
    def bestSolution2(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        if n - 1 not in self.memo:
            self.memo[n - 1] = self.bestSolution2(n - 1)
        if n - 2 not in self.memo:
            self.memo[n - 2] = self.bestSolution2(n - 2)
        return self.memo[n - 1] + self.memo[n - 2]

    # textbook LRU cache
    @lru_cache(maxsize=None)
    def bestSolution3(self, n: int) -> int:
        if n < 2:
            return n
        return self.bestSolution3(n - 1) + self.bestSolution3(n - 2)

    # iterative space-optimized
    def bestSolution4(self, n: int) -> int:
        if n == 0:
            return 0
        memo = [0, 1]
        for _ in range(2, n + 1):
            memo = [memo[-1], memo[-1] + memo[-2]]
        return memo[-1]

    # tuple
    def bestSolution5(self, n: int) -> int:
        if n == 0:
            return 0
        memo = (0, 1)
        for _ in range(2, n + 1):
            memo = (memo[-1], memo[-1] + memo[-2])
        return memo[-1]

    # golden ratio
    def bestSolution6(self, n: int) -> int:
        golden_ratio = (1 + 5**0.5) / 2
        return int((golden_ratio**n + 1) / 5**0.5)
