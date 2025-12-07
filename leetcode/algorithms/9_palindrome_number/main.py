class PalindromeNumber:
    """
    # Complexities:
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def isPalindrome(self, x: int) -> bool:
        result = True

        if x < 0:
            result = False

        xStr = str(x)

        for i in range(0, len(xStr) - 1):
            if i == len(xStr) - 1 - i:
                break
            if xStr[i] != xStr[len(xStr) - 1 - i]:
                result = False

        return result


    # Solution
    """
    # Solution 1
    #
    # String Conversion
    #
    # Complexities:
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(logᴺ)
    """
    def solution1(self, x: int) -> bool:
        if x < 0:
            return False

        s = str(x)

        return s == s[::-1]

    """
    # Solution 2
    #
    # Revert Half of the Number
    #
    # Complexities:
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(logᴺ)
    """
    def solution2(self, x: int) -> bool:
        if x < 0 or (x % 10 == 0 and x != 0):
            return False

        reverted_number = 0

        while x > reverted_number:
            reverted_number = reverted_number * 10 + x % 10
            x //= 10

        return x == reverted_number or x == reverted_number // 10
