import math


class ArrangingCoins:
    """
    # Complexities:
    #   N - `n`
    #   - Time Complexity: O(√N)
    #   - Space Complexity: O(1)
    """
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
    """
    # Solution 1
    #
    # Complexities:
    #   N - `n`
    #   - Time Complexity: O(√N)
    #   - Space Complexity: O(1)
    """
    def solution1(self, n: int) -> int:
        row = 0

        while n >= row + 1:
            row += 1
            n -= row

        return row

    """
    # Solution 2
    #
    # Binary Search
    #
    # Complexities:
    #   N - `n`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(1)
    """
    def solution2(self, n: int) -> int:
        left, right = 0, n

        while left <= right:
            mid = left + (right - left) // 2
            coins = mid * (mid + 1) // 2

            if coins == n:
                return mid
            elif coins < n:
                left = mid + 1
            else:
                right = mid - 1

        return right

    """
    # Solution 3
    #
    # Quadratic Formula
    #
    # Complexities:
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(1)
    """
    def solution3(self, n: int) -> int:
        return (math.isqrt(8 * n + 1) - 1) // 2
