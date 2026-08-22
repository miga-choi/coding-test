import math


class PowerOfFour:
    """
    # Built-in function
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def isPowerOfFour(self, n: int) -> bool:
        if n > 0 and math.log10(n) / math.log10(4) % 1 == 0:
            return True

        return False


    # Solution
    """
    # Solution 1
    #
    # Repeated Division
    #
    # Complexities:
    #   N - `n`
    #   - Time Complexity: O(log₄ᴺ)
    #   - Space Complexity: O(1)
    """
    def solution1(self, n: int) -> bool:
        if n < 1:
            return False

        while n % 4 == 0:
            n //= 4

        return n == 1

    """
    # Solution 2
    #
    # Bit Trick
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution2(self, n: int) -> bool:
        return n > 0 and n & (n - 1) == 0 and n & 0x55555555 != 0

    """
    # Solution 3
    #
    # Remaining 3
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution3(self, n: int) -> bool:
        return n > 0 and n & (n - 1) == 0 and (n - 1) % 3 == 0
