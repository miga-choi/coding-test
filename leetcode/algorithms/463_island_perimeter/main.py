from typing import List


class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        result = 0

        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 0:
                    continue

                result += 4

                if j > 0 and grid[i][j - 1] == 1:
                    result -= 2
                if i > 0 and grid[i - 1][j] == 1:
                    result -= 2

        return result


    # Best Solution
    def bestSolution(self, grid: List[List[int]]) -> int:
        m, n, Perimeter = len(grid), len(grid[0]), 0

        for i in range(m):
            for j in range(n):
                Perimeter += 4 * grid[i][j]
                if i > 0:
                    Perimeter -= grid[i][j] * grid[i - 1][j]
                if i < m - 1:
                    Perimeter -= grid[i][j] * grid[i + 1][j]
                if j > 0:
                    Perimeter -= grid[i][j] * grid[i][j - 1]
                if j < n - 1:
                    Perimeter -= grid[i][j] * grid[i][j + 1]

        return Perimeter
