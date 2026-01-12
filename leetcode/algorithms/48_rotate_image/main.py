from typing import List


class RotateImage:
    """
    # Transpose & Reverse
    #
    # Complexities:
    #   N - Length of `matrix`
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(1)
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
    # Transpose & Reverse
    #
    # Complexities:
    #   N - Length of `matrix`
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(1)
    """
    def solution1(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        
        for i in range(n):
            for j in range(i, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
        for i in range(n):
            matrix[i].reverse()

    """
    # Solution 2
    #
    # Layer-by-Layer Rotation
    #
    # Complexities:
    #   N - Length of `matrix`
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(1)
    """
    def solution2(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        left, right = 0, n - 1
        
        while left < right:
            for i in range(right - left):
                top, bottom = left, right
                
                temp = matrix[top][left + i]
                
                matrix[top][left + i] = matrix[bottom - i][left]
                
                matrix[bottom - i][left] = matrix[bottom][right - i]
                
                matrix[bottom][right - i] = matrix[top + i][right]
                
                matrix[top + i][right] = temp
            
            left += 1
            right -= 1
