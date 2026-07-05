class PowerOfTwo:
    """
    # Complexities:
    #   N - `n`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(1)
    """
    def isPowerOfTwo(self, n: int) -> bool:
        m = 0

        while 2**m <= n:
            if 2**m == n:
                return True
            m = m + 1

        return False


    # Solution
    """
    # Solution 1
    #
    # Bit Manipulation
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution1(self, n: int) -> bool:
        return n > 0 and (n & (n - 1)) == 0

    """
    # Solution 2
    #
    # 최하위 비트(LSB) 추출
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution2(self, n: int) -> bool:
        return n > 0 and (n & -n) == n

    """
    # Solution 3
    #
    # Built-in Function
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution3(self, n: int) -> bool:
        return n > 0 and n.bit_count() == 1
