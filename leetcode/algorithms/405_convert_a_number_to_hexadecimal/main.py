import math


class ConvertANumberToHexadecimal:
    """
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    #
    """
    def toHex(self, num: int) -> str:
        hex: slice = [
            "0",
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "a",
            "b",
            "c",
            "d",
            "e",
            "f",
        ]

        if num == 0:
            return "0"

        if num < 0:
            num += math.pow(2, 32)

        result = ""

        while num > 0:
            remainder = num % 16
            result = hex[int(remainder)] + result
            num = math.floor(num / 16)

        return result


    # Solution
    """
    # Solution 1
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    #
    """
    def solution1(self, num: int) -> str:
        if num == 0:
            return "0"

        digits = "0123456789abcdef"
        num &= 0xFFFFFFFF
        result = []

        while num:
            result.append(digits[num & 0xF])
            num >>= 4

        return ''.join(reversed(result))

    """
    # Solution 2
    #
    # Built-in Function
    #
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    #
    """
    def solution2(self, num: int) -> str:
        return format(num & 0xFFFFFFFF, "x") if num else "0"
