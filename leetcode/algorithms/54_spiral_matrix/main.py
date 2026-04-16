from typing import List


class SpiralMatrix:
    """
    # Layer Peeling
    #
    # Complexities:
    #   M - matrixSize
    #   N - matrixColSize
    #   - Time Complexity: O(M * N)
    #   - Space Complexity: O(M * N)
    """
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m: int = len(matrix)

        if m == 1:
            return matrix[0]

        n: int = len(matrix[0])

        result: List[int] = []

        top: int = 0
        bottom: int = m - 1
        left: int = 0
        right: int = n - 1

        while top <= bottom and left <= right:
            # [top][left -> right]
            for col in range(left, right + 1):
                result.append(matrix[top][col])
            top += 1

            # [top -> bottom][right]
            for row in range(top, bottom + 1):
                result.append(matrix[row][right])
            right -= 1

            # [bottom][right -> left]
            if top <= bottom:
                for col in range(right, left - 1, -1):
                    result.append(matrix[bottom][col])
                bottom -= 1

            # [bottom -> top][left]
            if left <= right:
                for row in range(bottom, top - 1, -1):
                    result.append(matrix[row][left])
                left += 1

        return result


    # Solution
    """
    # Layer Peeling
    #
    # Complexities:
    #   M - matrixSize
    #   N - matrixColSize
    #   - Time Complexity: O(M * N)
    #   - Space Complexity: O(M * N)
    """
    def solution(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []

        m, n = len(matrix), len(matrix[0])
        result = []
        top, bottom, left, right = 0, m - 1, 0, n - 1

        while left <= right and top <= bottom:
            # top, left -> right
            for j in range(left, right + 1):
                result.append(matrix[top][j])
            top += 1

            # top -> bottom, right
            for i in range(top, bottom + 1):
                result.append(matrix[i][right])
            right -= 1

            # bottom, right -> left && check boundary
            if top <= bottom:
                for j in range(right, left - 1, -1):
                    result.append(matrix[bottom][j])
                bottom -= 1

            # bottom -> top, left && check boundary
            if left <= right:
                for i in range(bottom, top - 1, -1):
                    result.append(matrix[i][left])
                left += 1

        return result
