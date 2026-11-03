class IslandPerimeter {
    /**
     * Grid Iteration (Counting Shared Edges)
     * 
     * Complexities:
     *   R - The Number of Row in `grid`
     *   C - The Number of Column in `grid`
     *   - Time Complexity: O(R * C)
     *   - Space Complexity: O(1)
     */
    public int islandPerimeter(int[][] grid) {
        int result = 0;

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }

                result += 4;

                if (j > 0 && grid[i][j - 1] == 1) {
                    result -= 2;
                }
                if (i > 0 && grid[i - 1][j] == 1) {
                    result -= 2;
                }
            }
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Grid Iteration (Counting Shared Edges)
     * 
     * Complexities:
     *   R - The Number of Row in `grid`
     *   C - The Number of Column in `grid`
     *   - Time Complexity: O(R * C)
     *   - Space Complexity: O(1)
     */
    public int solution1(int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        int perimeter = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    continue;
                }

                perimeter += 4;
                if (r > 0 && grid[r - 1][c] == 1) {
                    perimeter -= 2; // 위쪽 이웃
                }
                if (c > 0 && grid[r][c - 1] == 1) {
                    perimeter -= 2; // 왼쪽 이웃
                }
            }
        }

        return perimeter;
    }

    /**
     * Solution 2
     * 
     * Depth-First Search (DFS)
     * 
     * Complexities:
     *   R - The Number of Row in `grid`
     *   C - The Number of Column in `grid`
     *   - Time Complexity: O(R * C)
     *   - Space Complexity: O(R * C)
     */
    private int dfs(int[][] grid, int r, int c) {
        if (r < 0 || r >= grid.length || c < 0 || c >= grid[0].length || grid[r][c] == 0) {
            return 1;
        }

        if (grid[r][c] == 2) {
            return 0;
        }

        grid[r][c] = 2;
        return dfs(grid, r - 1, c) + dfs(grid, r + 1, c) + dfs(grid, r, c - 1) + dfs(grid, r, c + 1);
    }

    public int solution2(int[][] grid) {
        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                if (grid[r][c] == 1) {
                    return dfs(grid, r, c);
                }
            }
        }

        return 0;
    }
}
