from typing import List


class PascalsTriangle:
    """
    # DP
    # 
    # Complexities:
    #   N - `numRows`
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(N²)
    """
    def generate(self, numRows: int) -> List[List[int]]:
        result = []

        for i in range(0, numRows):
            row = []
            for j in range(0, i + 1):
                if j == 0 or j == i:
                    row.append(1)
                else:
                    row.append(result[i - 1][j - 1] + result[i - 1][j])

            result.append(row)

        return result


    # Solution
    """
    # Solution 1
    #
    # DP
    # 
    # Complexities:
    #   N - `numRows`
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(N²)
    """
    def solution1(self, numRows: int) -> List[List[int]]:
        triangle = []

        for i in range(numRows):
            row = [1] * (i + 1)

            for j in range(1, i):
                row[j] = triangle[i-1][j-1] + triangle[i-1][j]

            triangle.append(row)

        return triangle

    """
    # Solution 2
    #
    # Pythonic Way - zip
    # 
    # Complexities:
    #   N - `numRows`
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(N²)
    """
    def solution2(self, numRows: int) -> List[List[int]]:
        triangle = [[1]]

        for _ in range(numRows - 1):
            prev_row = triangle[-1]

            new_row = [a + b for a, b in zip([0] + prev_row, prev_row + [0])]

            triangle.append(new_row)

        return triangle
