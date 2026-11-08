class NumberComplement:
    """
    # String Conversion (Binary String Flip)
    #
    # Complexities:
    #   N - The Bit Length of 'num'
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(N)
    """
    def findComplement(self, num: int) -> int:
        binary = "{0:b}".format(num)
        result = ""

        for i in binary:
            if i == "1":
                result += "0"
            else:
                result += "1"

        return int(result, 2)


    # Solution
    """
    # Solution 1
    #
    # String Conversion
    #
    # Complexities:
    #   N - The Bit Length of 'num'
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution1(self, num: int) -> int:
        # return int(bin(num)[2:].translate(str.maketrans('01', '10')), 2)

        flipped = ''.join('1' if b == '0' else '0' for b in bin(num)[2:])
        return int(flipped, 2)

    """
    # Solution 2
    #
    # Bit-by-Bit Flipping
    #
    # Complexities:
    #   N - The Bit Length of 'num'
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution2(self, num: int) -> int:
        result = 0
        shift = 0

        while num:
            flipped = (num & 1) ^ 1
            result |= flipped << shift
            num >>= 1
            shift += 1

        return result

    """
    # Solution 3
    #
    # Iterative Mask Building
    #
    # Complexities:
    #   N - The Bit Length of 'num'
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution3(self, num: int) -> int:
        mask = 1

        while mask < num:
            mask = (mask << 1) | 1

        return num ^ mask

    """
    # Solution 4
    #
    # Bit Length Mask
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution4(self, num: int) -> int:
        mask = (1 << num.bit_length()) - 1
        return num ^ mask

    """
    # Solution 5
    #
    # Bit Smearing
    #
    # Complexities:
    #   N - The Bit Length of 'num'
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(1)
    """
    def solution5(self, num: int) -> int:
        mask = num
        mask |= mask >> 1
        mask |= mask >> 2
        mask |= mask >> 4
        mask |= mask >> 8
        mask |= mask >> 16
        return num ^ mask
