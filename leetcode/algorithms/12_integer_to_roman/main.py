from typing import List


class IntegerToRoman:
    """
    # Greedy
    # 
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def intToRoman(self, num: int) -> str:
        numbers: List[int] = [1000, 900, 500,
                              400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        characters: List[str] = ["M", "CM", "D", "CD", "C",
                                 "XC", "L", "XL", "X", "IX", "V", "IV", "I"]

        result: str = ""

        i: int = 0
        while True:
            while num >= numbers[i]:
                num -= numbers[i]
                result += characters[i]

            if num <= 0:
                break

            i += 1

        return result


    # Solution
    """
    # Solution 1
    #
    # Greedy
    # 
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution1(self, num: int) -> str:
        value_symbol_pairs = [
            (1000, "M"),
            (900, "CM"),
            (500, "D"),
            (400, "CD"),
            (100, "C"),
            (90, "XC"),
            (50, "L"),
            (40, "XL"),
            (10, "X"),
            (9, "IX"),
            (5, "V"),
            (4, "IV"),
            (1, "I"),
        ]

        result = []

        for value, symbol in value_symbol_pairs:
            if num == 0:
                break

            count, num = divmod(num, value)

            result.append(symbol * count)

        return "".join(result)

    """
    # Solution 2
    #
    # Hard Coding
    # 
    # Complexities:
    #   - Time Complexity: O(1)
    #   - Space Complexity: O(1)
    """
    def solution2(self, num: int) -> str:
        M = ["", "M", "MM", "MMM"]
        C = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
        X = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
        I = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]

        return M[num // 1000] + C[(num % 1000) // 100] + X[(num % 100) // 10] + I[num % 10]
