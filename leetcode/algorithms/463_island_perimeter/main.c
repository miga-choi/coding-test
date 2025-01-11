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

// Best Solution
int bestSolution(int** grid, int gridSize, int* gridColSize) {
    int count = 0, repeat = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                count++;
                if (i != 0 && grid[i - 1][j] == 1) {
                    repeat++;
                }
                if (j != 0 && grid[i][j - 1] == 1) {
                    repeat++;
                }
            }
        }
    }
    return 4 * count - repeat * 2;
}
