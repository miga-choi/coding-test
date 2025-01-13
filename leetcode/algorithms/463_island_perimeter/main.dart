class IslandPerimeter {
  int islandPerimeter(List<List<int>> grid) {
    int cnt = 0;
    for (int i = 0; i < grid.length; i++) {
      for (int j = 0; j < grid[i].length; j++) {
        if (grid[i][j] > 0) {
          cnt += 4;
          if (i > 0 && grid[i - 1][j] > 0) {
            cnt -= 2;
          }
          if (j > 0 && grid[i][j - 1] > 0) {
            cnt -= 2;
          }
        }
      }
    }
    return cnt;
  }

  // Best Solution
  int bestSolution(List<List<int>> grid) {
    int ans = 0;
    for (int i = 0; i < grid.length; i++) {
      for (int j = 0; j < grid[0].length; j++) {
        if (grid[i][j] == 0) {
          continue;
        }
        if (i - 1 < 0 || grid[i - 1][j] == 0) {
          ans++;
        }
        if (j - 1 < 0 || grid[i][j - 1] == 0) {
          ans++;
        }
        if (i + 1 >= grid.length || grid[i + 1][j] == 0) {
          ans++;
        }
        if (j + 1 >= grid[0].length || grid[i][j + 1] == 0) {
          ans++;
        }
      }
    }
    return ans;
  }
}
