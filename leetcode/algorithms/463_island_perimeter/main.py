from typing import List


class IslandPerimeter:
    """
    # Shared Edge Counting
    #
    # Complexities:
    #   R - The Number of Row in `grid`
    #   C - The Number of Column in `grid`
    #   - Time Complexity: O(R * C)
    #   - Space Complexity: O(1)
    """
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


    # Solution
    """
    # Solution 1
    #
    # Neighbor Counting
    #
    # Complexities:
    #   R - The Number of Row in `grid`
    #   C - The Number of Column in `grid`
    #   - Time Complexity: O(R * C)
    #   - Space Complexity: O(1)
    """
    def solution1(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        perimeter = 0

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 0:
                    continue
                perimeter += 4
                for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == 1:
                        perimeter -= 1

        return perimeter

    """
    # Solution 2
    #
    # Shared Edge Counting
    #
    # Complexities:
    #   R - The Number of Row in `grid`
    #   C - The Number of Column in `grid`
    #   - Time Complexity: O(R * C)
    #   - Space Complexity: O(1)
    """
    def solution2(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        land = shared = 0

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    land += 1
                    if r > 0 and grid[r - 1][c] == 1:
                        shared += 1
                    if c > 0 and grid[r][c - 1] == 1:
                        shared += 1

        return 4 * land - 2 * shared

    """
    # Solution 3
    #
    # Depth-First Search (DFS)
    #
    # Complexities:
    #   R - The Number of Row in `grid`
    #   C - The Number of Column in `grid`
    #   - Time Complexity: O(R * C)
    #   - Space Complexity: O(R * C)
    """
    def solution3(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])

        start = next((r, c) for r in range(rows) for c in range(cols) if grid[r][c] == 1)

        perimeter = 0
        visited = {start}
        stack = [start]

        while stack:
            r, c = stack.pop()

            for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                nr, nc = r + dr, c + dc

                if not (0 <= nr < rows and 0 <= nc < cols) or grid[nr][nc] == 0:
                    perimeter += 1
                elif (nr, nc) not in visited:
                    visited.add((nr, nc))
                    stack.append((nr, nc))

        return perimeter
