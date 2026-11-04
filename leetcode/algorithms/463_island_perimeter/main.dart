class IslandPerimeter {
  /**
   * Shared Edge Counting
   * 
   * Complexities:
   *   R - The Number of Row in `grid`
   *   C - The Number of Column in `grid`
   *   - Time Complexity: O(R * C)
   *   - Space Complexity: O(1)
   */
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


  // Solution
  /**
   * Solution 1
   * 
   * Neighbor Check
   * 
   * Complexities:
   *   R - The Number of Row in `grid`
   *   C - The Number of Column in `grid`
   *   - Time Complexity: O(R * C)
   *   - Space Complexity: O(1)
   */
  int solution1(List<List<int>> grid) {
    final rows = grid.length;
    final cols = grid[0].length;
    var perimeter = 0;

    for (var r = 0; r < rows; r++) {
      for (var c = 0; c < cols; c++) {
        if (grid[r][c] == 0) {
          continue;
        }

        if (r == 0 || grid[r - 1][c] == 0) {
          perimeter++;
        }

        if (r == rows - 1 || grid[r + 1][c] == 0) {
          perimeter++;
        }

        if (c == 0 || grid[r][c - 1] == 0) {
          perimeter++;
        }

        if (c == cols - 1 || grid[r][c + 1] == 0) {
          perimeter++;
        }
      }
    }

    return perimeter;
  }

  /**
   * Solution 2
   * 
   * Shared Edge Counting
   * 
   * Complexities:
   *   R - The Number of Row in `grid`
   *   C - The Number of Column in `grid`
   *   - Time Complexity: O(R * C)
   *   - Space Complexity: O(1)
   */
  int solution2(List<List<int>> grid) {
    var land = 0;
    var shared = 0;

    for (var r = 0; r < grid.length; r++) {
      final row = grid[r];

      for (var c = 0; c < row.length; c++) {
        if (row[c] == 0) {
          continue;
        }

        land++;

        if (r > 0 && grid[r - 1][c] == 1) {
          shared++;
        }

        if (c > 0 && row[c - 1] == 1) {
          shared++;
        }
      }
    }

    return land * 4 - shared * 2;
  }

  /**
   * Solution 3
   * 
   * Depth-First Search (DFS)
   * 
   * Complexities:
   *   R - The Number of Row in `grid`
   *   C - The Number of Column in `grid`
   *   - Time Complexity: O(R * C)
   *   - Space Complexity: O(R * C)
   */
  int solution3(List<List<int>> grid) {
    final rows = grid.length;
    final cols = grid[0].length;
    final visited = List.generate(rows, (_) => List<bool>.filled(cols, false));

    int dfs(int r, int c) {
      if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
        return 1;
      }

      if (visited[r][c]) {
        return 0;
      }

      visited[r][c] = true;

      return dfs(r - 1, c) + dfs(r + 1, c) + dfs(r, c - 1) + dfs(r, c + 1);
    }

    for (var r = 0; r < rows; r++) {
      for (var c = 0; c < cols; c++) {
        if (grid[r][c] == 1) {
          return dfs(r, c);
        }
      }
    }

    return 0;
  }
}
