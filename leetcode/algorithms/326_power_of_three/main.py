class PowerOfThree:
    """
    # Complexities:
    #   N - `n`
    #   - Time Complexity: O(log₃ᴺ)
    #   - Space Complexity: O(1)
    """
    def isPowerOfThree(self, n: int) -> bool:
        if n < 1:
            return False

        while n % 3 == 0:
            n //= 3

        return n == 1


    # Solution
    """
    # Solution 1
    #
    # Complexities:
    #   N - `n`
    #   - Time Complexity: O(log₃ᴺ)
    #   - Space Complexity: O(1)
    """
    def solution1(self, n: int) -> bool:
        if n < 1:
            return False

        while n % 3 == 0:
            n //= 3

        return n == 1

    """
    # Solution 2
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution2(self, n: int) -> bool:
        return n > 0 and 1162261467 % n == 0
