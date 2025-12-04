class ZigzagConversion:
    """
    # Complexities:
    #   N - Length of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def convert(self, s: str, numRows: int) -> str:
        sLen: int = len(s)

        if numRows == 1 or numRows > sLen:
            return s

        cycleLen: int = numRows * 2 - 2
        result: str = ""

        for row in range(numRows):
            for cycle in range(row, sLen, cycleLen):
                result += s[cycle]

                if row > 0 and row < numRows - 1:
                    diag_idx: int = cycle + cycleLen - row * 2
                    if diag_idx < sLen:
                        result += s[diag_idx]

        return result


    # Solution
    """
    # Solution 1
    #
    # Complexities:
    #   N - Length of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution1(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s

        rows = [''] * numRows
        current_row = 0
        direction = -1

        for char in s:
            rows[current_row] += char

            if current_row == 0 or current_row == numRows - 1:
                direction *= -1

            current_row += direction

        return "".join(rows)

    """
    # Solution 2
    #
    # Complexities:
    #   N - Length of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution2(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s

        n = len(s)
        result = []
        cycle_len = 2 * numRows - 2

        for i in range(numRows):
            for j in range(i, n, cycle_len):
                result.append(s[j])

                if 0 < i < numRows - 1:
                    diagonal_index = j + cycle_len - 2 * i
                    if diagonal_index < n:
                        result.append(s[diagonal_index])

        return "".join(result)
