class NumberOf1Bits:
    """
    # Built-in Function
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def hammingWeight(self, n: int) -> int:
        n = bin(n).replace("0b", "")
        result = 0

        for c in n:
            if c == "1":
                result += 1

        return result


    # Solution
    """
    # Solution 1
    #
    # Brian Kernighan's Algorithm
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution1(self, n: int) -> int:
        count = 0

        while n > 0:
            n &= (n - 1)
            count += 1

        return count

    """
    # Solution 2
    #
    # Shift & Mask
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution2(self, n: int) -> int:
        count = 0

        while n > 0:
            count += n & 1
            n >>= 1

        return count

    """
    # Solution 3
    #
    # Built-in Function
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution3(self, n: int) -> int:
        # return bin(n).count('1')
        return n.bit_count()
