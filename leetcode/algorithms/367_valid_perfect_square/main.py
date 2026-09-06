import math


class ValidPerfectSquare:
    """
    # Complexities:
    #   N - `num`
    #   - Time Complexity: O(√N)
    #   - Space Complexity: O(1)
    """
    def isPerfectSquare(self, num: int) -> bool:
        i = 0

        while True:
            if i**2 == num:
                return True
            elif i**2 > num:
                return False
            else:
                i = i + 1


    # Solution
    """
    # Solution 1
    #
    # Binary Search
    #
    # Complexities:
    #   N - `num`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(1)
    """
    def solution1(self, num: int) -> bool:
        if num < 2:
            return True

        left, right = 2, num // 2

        while left <= right:
            mid = left + (right - left) // 2
            square = mid * mid

            if square == num:
                return True
            elif square < num:
                left = mid + 1
            else:
                right = mid - 1

        return False

    """
    # Solution 2
    #
    # Sum of Odd Numbers
    #
    # Complexities:
    #   N - `num`
    #   - Time Complexity: O(√N)
    #   - Space Complexity: O(1)
    """
    def solution2(self, num: int) -> bool:
        odd = 1

        while num > 0:
            num -= odd
            odd += 2

        return num == 0

    """
    # Solution 3
    #
    # Newton-Raphson Method
    #
    # Complexities:
    #   N - `num`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(1)
    """
    def solution3(self, num: int) -> bool:
        x = num

        while x * x > num:
            x = (x + num // x) // 2

        return x * x == num

    """
    # Solution 4
    #
    # math.isqrt
    #
    # Complexities:
    #   N - `num`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(1)
    """
    def solution4(self, num: int) -> bool:
        r = math.isqrt(num)

        return r * r == num
