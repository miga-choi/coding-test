class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        roman = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000,
        }

        s = s.replace("IV", "IIII").replace("IX", "VIIII").replace("XL", "XXXX").replace(
            "XC", "LXXXX").replace("CD", "CCCC").replace("CM", "DCCCC")

        result = 0

        for char in s:
            result += roman[char]

        return result
