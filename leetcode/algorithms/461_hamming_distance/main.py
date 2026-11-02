class HammingDistance:
    """
    # XOR + String Conversion
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def hammingDistance(self, x: int, y: int) -> int:
        return len("{0:b}".format(x ^ y).replace("0", ""))


    # Solution
    """
    # Solution 1
    #
    # XOR + Built-in Popcount
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution1(self, x: int, y: int) -> int:
        return (x ^ y).bit_count()

    """
    # Solution 2
    #
    # XOR + Bit Shifting
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution2(self, x: int, y: int) -> int:
        z = x ^ y
        count = 0

        while z:
            count += z & 1
            z >>= 1

        return count

    """
    # Solution 3
    #
    # XOR + Brian Kernighan’s Algorithm
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution3(self, x: int, y: int) -> int:
        z = x ^ y
        count = 0

        while z:
            z &= z - 1
            count += 1

        return count
