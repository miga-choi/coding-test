class ExcelSheetColumnNumber:
    """
    # Complexities:
    #   N - Size of `columnTitle`
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(1)
    """
    def titleToNumber(self, columnTitle: str) -> int:
        result = 0

        for i in range(len(columnTitle)):
            result += 26**i * (ord(columnTitle[::-1][i]) - 64)

        return result


    # Solution
    """
    # Complexities:
    #   N - Size of `columnTitle`
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(1)
    """
    def solution(self, columnTitle: str) -> int:
        result = 0

        for char in columnTitle:
            val = ord(char) - ord('A') + 1

            result = result * 26 + val

        return result
