from typing import List


class PascalsTriangleII:
    """
    # DP
    #
    # Complexities:
    #   N - `rowIndex`
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(N)
    """
    def getRow(self, rowIndex: int) -> List[int]:
        rows = []

        for i in range(rowIndex + 1):
            row = []

            for j in range(i + 1):
                if j == 0 or j == i:
                    row.append(1)
                else:
                    row.append(rows[i - 1][j - 1] + rows[i - 1][j])

            rows.append(row)

        return rows[rowIndex]


    # Solution
    """
    # Solution 1
    #
    # DP
    #
    # Complexities:
    #   N - `rowIndex`
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(N)
    """
    def solution1(self, rowIndex: int) -> List[int]:
        row = [1] * (rowIndex + 1)

        for i in range(2, rowIndex + 1):
            for j in range(i - 1, 0, -1):
                row[j] = row[j] + row[j - 1]

        return row

    """
    # Solution 2
    #
    # Binomial Coefficient
    #
    # Complexities:
    #   N - `rowIndex`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution1(self, rowIndex: int) -> List[int]:
        row = [1] * (rowIndex + 1)

        for i in range(1, rowIndex):
            row[i] = row[i - 1] * (rowIndex - i + 1) // i

        return row
