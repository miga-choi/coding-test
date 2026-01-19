from typing import List


class SetMatrixZeroes:
    """
    # Marking First Row and Column as Flag
    #
    # Complexities:
    #   M - Length of `matrix`
    #   N - Length of `matrix[0]`
    #   - Time Complexity: O(M * N)
    #   - Space Complexity: O(1)
    """
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        isFirstRowZero: bool = False
        isFirstColZero: bool = False

        m: int = len(matrix)
        n: int = len(matrix[0])

        for row in range(0, m):
            if matrix[row][0] == 0:
                isFirstColZero = True
                break

        for col in range(0, n):
            if matrix[0][col] == 0:
                isFirstRowZero = True
                break

        for row in range(1, m):
            for col in range(1, n):
                if matrix[row][col] == 0:
                    matrix[row][0] = 0
                    matrix[0][col] = 0

        for row in range(1, m):
            for col in range(1, n):
                if matrix[row][0] == 0 or matrix[0][col] == 0:
                    matrix[row][col] = 0

        if isFirstColZero:
            for row in range(0, m):
                matrix[row][0] = 0

        if isFirstRowZero:
            for col in range(0, n):
                matrix[0][col] = 0


    # Solution
    """
    # Marking First Row and Column as Flag
    #
    # Complexities:
    #   M - Length of `matrix`
    #   N - Length of `matrix[0]`
    #   - Time Complexity: O(M * N)
    #   - Space Complexity: O(1)
    """
    def solution(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = len(matrix)
        cols = len(matrix[0])
        is_col0 = False

        for i in range(rows):
            if matrix[i][0] == 0:
                is_col0 = True

            for j in range(1, cols):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0

        for i in range(1, rows):
            for j in range(1, cols):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0

        if matrix[0][0] == 0:
            for j in range(cols):
                matrix[0][j] = 0

        if is_col0:
            for i in range(rows):
                matrix[i][0] = 0
