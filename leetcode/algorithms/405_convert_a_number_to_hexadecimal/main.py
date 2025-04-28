import math


class ConvertANumberToHexadecimal:
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
    def solution(self, num: int) -> str:
        if num == 0:
            return "0"

        map = "0123456789abcdef"
        result = ""

        # if negative (two's compliment)
        if num < 0:
            num += 2**32

        while num > 0:
            digit = num % 16
            num = (num - digit) // 16
            result += str(map[digit])

        return result[::-1]
