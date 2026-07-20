class AddDigits:
    """
    # Iterative
    #
    # Complexities:
    #   - Time Complexity: O(log₁₀ᴺ)
    #   - Space Complexity: O(1)
    """
    def addDigits(self, num: int) -> int:
        numString = str(num)

        while len(numString) > 1:
            num = 0

            for i in range(len(numString)):
                num += int(numString[i])

            numString = str(num)

        return num


    # Solution
    """
    # Solution 1
    #
    # Digital Root
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution1(self, num: int) -> int:
        if num == 0:
            return 0

        return 1 + (num - 1) % 9

    """
    # Solution 2
    #
    # Iterative
    #
    # Complexities:
    #   - Time Complexity: O(log₁₀ᴺ)
    #   - Space Complexity: O(1)
    """
    def solution2(self, num: int) -> int:
        while num >= 10:
            total_sum = 0

            while num > 0:
                num, digit = divmod(num, 10)
                total_sum += digit

            num = total_sum

        return num
