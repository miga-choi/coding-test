/**
 * Counting Land and Shared Edges
 * 
 * Complexities:
 *   R - `rows`
 *   C - `cols`
 *   - Time Complexity: O(R * C)
 *   - Space Complexity: O(1)
 */
int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int cnt = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j]) {
                cnt += 4;
                if (i > 0) {
                    if (grid[i - 1][j]) {
                        cnt -= 2;
                    }
                }
                if (j > 0) {
                    if (grid[i][j - 1]) {
                        cnt -= 2;
                    }
                }
            }
        }
    }

    return cnt;
}


// Solution
/**
 * Solution 1
 * 
 * Matrix Traversal + Neighbor Check
 * 
 * Complexities:
 *   R - `rows`
 *   C - `cols`
 *   - Time Complexity: O(R * C)
 *   - Space Complexity: O(1)
 */
int solution1(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize, cols = gridColSize[0];
    int perim = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 0) continue;

            if (r == 0 || grid[r - 1][c] == 0) {
                perim++;
            }
            if (r == rows - 1 || grid[r + 1][c] == 0) {
                perim++;
            }
            if (c == 0 || grid[r][c - 1] == 0) {
                perim++;
            }
            if (c == cols - 1 || grid[r][c + 1] == 0) {
                perim++;
            }
        }
    }

    return perim;
}

/**
 * Solution 2
 * 
 * Counting Land and Shared Edges
 * 
 * Complexities:
 *   R - `rows`
 *   C - `cols`
 *   - Time Complexity: O(R * C)
 *   - Space Complexity: O(1)
 */
int solution2(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize, cols = gridColSize[0];
    int land = 0, shared = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 0) {
                continue;
            }

            land++;
            if (r > 0 && grid[r - 1][c] == 1) {
                shared++;
            }
            if (c > 0 && grid[r][c - 1] == 1) {
                shared++;
            }
        }
    }

    return 4 * land - 2 * shared;
}

/**
 * Solution 3
 * 
 * Depth-First Search (DFS)
 * 
 * Complexities:
 *   R - `rows`
 *   C - `cols`
 *   - Time Complexity: O(R * C)
 *   - Space Complexity: O(R * C)
 */
static int dfs(int** g, int rows, int cols, int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || g[r][c] == 0)
        return 1;                    // 경계나 물과 맞닿은 변 하나
    if (g[r][c] == 2)
        return 0;                    // 이미 방문한 땅

    g[r][c] = 2;                     // 방문 표시
    return dfs(g, rows, cols, r - 1, c)
         + dfs(g, rows, cols, r + 1, c)
         + dfs(g, rows, cols, r, c - 1)
         + dfs(g, rows, cols, r, c + 1);
}

int solution3(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize, cols = gridColSize[0];

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 1) {
                return dfs(grid, rows, cols, r, c);
            }
        }
    }

    return 0;
}
