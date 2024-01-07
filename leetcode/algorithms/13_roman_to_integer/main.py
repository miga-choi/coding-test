class RomanToInteger:
    def romanToInt(self, s: str) -> int:
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


    # Best Solution
    # Best Solution 1:
    def bestSolution1(self, s: str) -> int:
        translations = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }
        number = 0
        s = s.replace("IV", "IIII").replace("IX", "VIIII")
        s = s.replace("XL", "XXXX").replace("XC", "LXXXX")
        s = s.replace("CD", "CCCC").replace("CM", "DCCCC")
        for char in s:
            number += translations[char]
        return number

    # Best Solution 2:
    def bestSolution2(self, s: str) -> int:
        m = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }

        ans = 0

        for i in range(len(s)):
            if i < len(s) - 1 and m[s[i]] < m[s[i + 1]]:
                ans -= m[s[i]]
            else:
                ans += m[s[i]]

        return ans
