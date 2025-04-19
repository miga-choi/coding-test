from typing import List


class PascalsTriangleII:
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
    def solution(self, rowIndex: int) -> List[int]:
        row = [1] * (rowIndex + 1)
        if rowIndex == 0:
            return row
        prev_row = self.getRow(rowIndex - 1)
        for i in range(1, len(row) - 1):
            row[i] = prev_row[i - 1] + prev_row[i]
        return row
