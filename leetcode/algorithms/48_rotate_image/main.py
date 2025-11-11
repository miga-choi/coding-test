from typing import List


class RotateImage:
    """
    # Reverse & Transpose
    # - Time Complexity: O(N²)
    # - Space Complexity: O(1)
    """
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        length: int = len(matrix)

        # Reverse rows
        length: int = len(matrix)

        for row in range(length // 2):
            for col in range(length):
                temp: int = matrix[row][col]
                matrix[row][col] = matrix[length - 1 - row][col]
                matrix[length - 1 - row][col] = temp

        # Transpose diagonally
        for row in range(length):
            for col in range(row + 1, length):
                temp: int = matrix[row][col]
                matrix[row][col] = matrix[col][row]
                matrix[col][row] = temp


    # Solution
    """
    # Solution 1
    #
    # Transpose and Reflect
    # - Time Complexity: O(N²)
    # - Space Complexity: O(1)
    """
    def solution1(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)

        # Transpose the matrix
        for i in range(n):
            for j in range(i, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        # Reflect the matrix horizontally
        for i in range(n):
            matrix[i].reverse()

    """
    # Solution 2
    #
    # Rotate Layer by Layer
    # - Time Complexity: O(N²)
    # - Space Complexity: O(1)
    """
    def solution2(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        left, right = 0, n - 1

        while left < right:
            # top, bottom = left, right
            top, bottom = left, right

            # 레이어의 각 원소 그룹을 회전 (i는 오프셋)
            for i in range(right - left):
                # top-left -> temp
                topLeft = matrix[top][left + i]

                # bottom-left -> top-left
                matrix[top][left + i] = matrix[bottom - i][left]

                # bottom-right -> bottom-left
                matrix[bottom - i][left] = matrix[bottom][right - i]

                # top-right -> bottom-right
                matrix[bottom][right - i] = matrix[top + i][right]

                # temp -> top-right
                matrix[top + i][right] = topLeft

            # next inner layer
            left += 1
            right -= 1
