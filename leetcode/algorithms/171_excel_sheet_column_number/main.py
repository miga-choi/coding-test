class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        result = 0

        for i in range(len(columnTitle)):
            result += 26**i * (ord(columnTitle[::-1][i]) - 64)

        return result

    # Best Solution
    def bestSolution(self, columnTitle: str) -> int:
        ans, pos = 0, 0
        for letter in reversed(columnTitle):
            digit = ord(letter) - 64
            ans += digit * 26**pos
            pos += 1

        return ans
