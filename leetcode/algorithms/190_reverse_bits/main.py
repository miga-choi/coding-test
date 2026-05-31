class ReverseBits:
    """
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def reverseBits(self, n: int) -> int:
        n = bin(n).replace("0b", "")[::-1]

        while len(n) < 32:
            n += "0"

        return int(n, 2)


    # Solution
    """
    # Solution 1
    #
    # Bitwise Operations
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution1(self, n: int) -> int:
        res = 0

        for _ in range(32):
            res = (res << 1) | (n & 1)

            n >>= 1

        return res

    """
    # Solution 2
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution2(self, n: int) -> int:
        return int('{:032b}'.format(n)[::-1], 2)
