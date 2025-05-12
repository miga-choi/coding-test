from functools import lru_cache


class FibonacciNumber:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        elif n == 1:
            return 1
        else:
            return self.fib(n - 1) + self.fib(n - 2)


    # Solution
    # Solution 1: naive recursive
    def solution1(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        return self.bestSolution1(n - 1) + self.bestSolution1(n - 2)

    # Solution 2: memoized recursive
    memo = {}
    def solution2(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        if n - 1 not in self.memo:
            self.memo[n - 1] = self.bestSolution2(n - 1)
        if n - 2 not in self.memo:
            self.memo[n - 2] = self.bestSolution2(n - 2)
        return self.memo[n - 1] + self.memo[n - 2]

    # Solution 3: textbook LRU cache
    @lru_cache(maxsize=None)
    def solution3(self, n: int) -> int:
        if n < 2:
            return n
        return self.bestSolution3(n - 1) + self.bestSolution3(n - 2)

    # Solution 4: iterative space-optimized
    def solution4(self, n: int) -> int:
        if n == 0:
            return 0
        memo = [0, 1]
        for _ in range(2, n + 1):
            memo = [memo[-1], memo[-1] + memo[-2]]
        return memo[-1]

    # Solution 5: tuple
    def solution5(self, n: int) -> int:
        if n == 0:
            return 0
        memo = (0, 1)
        for _ in range(2, n + 1):
            memo = (memo[-1], memo[-1] + memo[-2])
        return memo[-1]

    # Solution 6: golden ratio
    def solution6(self, n: int) -> int:
        golden_ratio = (1 + 5**0.5) / 2
        return int((golden_ratio**n + 1) / 5**0.5)
