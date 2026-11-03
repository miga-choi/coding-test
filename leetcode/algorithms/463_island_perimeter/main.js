/**
 * Grid Iteration (Counting Shared Edges)
 *
 * Complexities:
 *   R - The Number of Row in `grid`
 *   C - The Number of Column in `grid`
 *   - Time Complexity: O(R * C)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[][]} grid
 * @return {number}
 */
var islandPerimeter = function (grid) {
  let result = 0;

  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[i].length; j++) {
      if (!grid[i][j]) {
        continue;
      }

      result += 4;

      if (j > 0 && grid[i][j - 1]) {
        result -= 2;
      }
      if (i > 0 && grid[i - 1][j]) {
        result -= 2;
      }
    }
  }

  return result;
};


// Solution
/**
 * Solution 1
 *
 * Grid Iteration (Counting Neighbors)
 *
 * Complexities:
 *   R - The Number of Row in `grid`
 *   C - The Number of Column in `grid`
 *   - Time Complexity: O(R * C)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[][]} grid
 * @return {number}
 */
var solution1 = function (grid) {
  const rows = grid.length;
  const cols = grid[0].length;

  var perimeter = 0;

  for (var row = 0; row < rows; row++) {
    for (var col = 0; col < cols; col++) {
      if (!grid[row][col]) {
        continue;
      }

      perimeter += 4;

      if (row > 0 && grid[row - 1][col]) {
        perimeter--;
      }
      if (col > 0 && grid[row][col - 1]) {
        perimeter--;
      }
      if (row < rows - 1 && grid[row + 1][col]) {
        perimeter--;
      }
      if (col < cols - 1 && grid[row][col + 1]) {
        perimeter--;
      }
    }
  }

  return perimeter;
};

/**
 * Solution 2
 *
 * Grid Iteration (Counting Shared Edges)
 *
 * Complexities:
 *   R - The Number of Row in `grid`
 *   C - The Number of Column in `grid`
 *   - Time Complexity: O(R * C)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[][]} grid
 * @return {number}
 */
var solution2 = function (grid) {
  let land = 0;
  let shared = 0;

  for (let r = 0; r < grid.length; r++) {
    for (let c = 0; c < grid[0].length; c++) {
      if (grid[r][c] !== 1) {
        continue;
      }

      land++;
      if (r > 0 && grid[r - 1][c] === 1) {
        shared++;
      }
      if (c > 0 && grid[r][c - 1] === 1) {
        shared++;
      }
    }
  }

  return 4 * land - 2 * shared;
};

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
/**
 * @param {number[][]} grid
 * @return {number}
 */
var solution3 = function (grid) {
  const rows = grid.length;
  const cols = grid[0].length;

  const dfs = (r, c) => {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] === 0) {
      return 1;
    }

    if (grid[r][c] === 2) {
      return 0;
    }

    grid[r][c] = 2;

    return dfs(r - 1, c) + dfs(r + 1, c) + dfs(r, c - 1) + dfs(r, c + 1);
  };

  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (grid[r][c] === 1) {
        return dfs(r, c);
      }
    }
  }

  return 0;
};

/**
 * Solution 4
 *
 * Breadth-First Search (BFS)
 *
 * Complexities:
 *   R - The Number of Row in `grid`
 *   C - The Number of Column in `grid`
 *   - Time Complexity: O(R * C)
 *   - Space Complexity: O(R * C)
 */
/**
 * @param {number[][]} grid
 * @return {number}
 */
var solution4 = function (grid) {
  const rows = grid.length;
  const cols = grid[0].length;
  const dirs = [
    [-1, 0],
    [1, 0],
    [0, -1],
    [0, 1],
  ];

  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (grid[r][c] !== 1) {
        continue;
      }

      let perimeter = 0;
      const queue = [[r, c]];
      let head = 0;
      grid[r][c] = 2;

      while (head < queue.length) {
        const [cr, cc] = queue[head++];

        for (const [dr, dc] of dirs) {
          const nr = cr + dr,
            nc = cc + dc;

          if (
            nr < 0 ||
            nr >= rows ||
            nc < 0 ||
            nc >= cols ||
            grid[nr][nc] === 0
          ) {
            perimeter++;
          } else if (grid[nr][nc] === 1) {
            grid[nr][nc] = 2;
            queue.push([nr, nc]);
          }
        }
      }

      return perimeter;
    }
  }
};
