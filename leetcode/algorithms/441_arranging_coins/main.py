import math


class ArrangingCoins:
    def arrangeCoins(self, n: int) -> int:
        stairs = 1
        while True:
            n -= stairs
            if n == 0:
                return stairs
            elif n < 0:
                return stairs - 1
            stairs += 1


    # Solution
    def solution(self, n: int) -> int:
        # int is simply to floor the floating point so we get the largest integer smaller than the expression
        return int((math.sqrt(8 * n + 1) - 1) / 2)
