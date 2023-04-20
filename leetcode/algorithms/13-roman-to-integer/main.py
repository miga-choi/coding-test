class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        roman = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }

        s = (
            s.replace("CM", "DCCCC")
            .replace("CD", "CCCC")
            .replace("XC", "LXXXX")
            .replace("XL", "XXXX")
            .replace("IX", "VIIII")
            .replace("IV", "IIII")
        )

        result = 0

        for char in s:
            result += roman[char]

        return result
