class ExcelSheetColumnTitle:
    """
    # Complexities:
    #   N - `columnNumber`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(logᴺ)
    """
    def convertToTitle(self, columnNumber: int) -> str:
        alphabet = [
            "A",
            "B",
            "C",
            "D",
            "E",
            "F",
            "G",
            "H",
            "I",
            "J",
            "K",
            "L",
            "M",
            "N",
            "O",
            "P",
            "Q",
            "R",
            "S",
            "T",
            "U",
            "V",
            "W",
            "X",
            "Y",
            "Z",
        ]

        result = ""

        while columnNumber > 0:
            result = alphabet[(columnNumber - 1) % 26] + result
            columnNumber = (columnNumber - 1) // 26

        return result


    # Solution
    """
    # Complexities:
    #   N - `columnNumber`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(logᴺ)
    """
    def solution(self, columnNumber):
        result = []
        
        while columnNumber > 0:
            columnNumber -= 1
            
            remainder = columnNumber % 26
            
            result.append(chr(ord('A') + remainder))
            
            columnNumber //= 26
            
        return "".join(result[::-1])