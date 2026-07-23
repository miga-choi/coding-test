class UglyNumber:
    """
    # Iterative Division
    #
    # Complexities:
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(N)
    """
    def isUgly(self, n: int) -> bool:
        if n < 1:
            return False

        while n > 1:
            if n % 5 == 0:
                n /= 5
            elif n % 3 == 0:
                n /= 3
            elif n % 2 == 0:
                n /= 2
            else:
                return False

        return True


    # Solution
    """
    # Iterative Division
    #
    # Complexities:
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(N)
    """
    def solution(self, num: int) -> bool:
        if n <= 0:
            return False

        for factor in [2, 3, 5]:
            while n % factor == 0:
                n //= factor

        return n == 1
