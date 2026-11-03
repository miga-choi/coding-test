#include <cstddef> // std::size_t
#include <vector>  // std::vector
using namespace std;

class IslandPerimeter {
public:
    /**
     * Matrix Traversal + Neighbor Check
     *
     * Complexities:
     *   R - The Number of Row in `grid`
     *   C - The Number of Column in `grid`
     *   - Time Complexity: O(R * C)
     *   - Space Complexity: O(1)
     */
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.at(i).size(); j++) {
                if (grid.at(i).at(j)) {
                    cnt += 4;

                    if (i > 0 && grid.at(i - 1).at(j)) {
                        cnt -= 2;
                    }
                    if (j > 0 && grid.at(i).at(j - 1)) {
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
     * Matrix Traversal + Neighbor Check
     *
     * Complexities:
     *   R - The Number of Row in `grid`
     *   C - The Number of Column in `grid`
     *   - Time Complexity: O(R * C)
     *   - Space Complexity: O(1)
     */
    int solution1(vector<vector<int>>& grid) {
        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());
        int perim = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    continue;
                }

                if (r == 0 || grid[r - 1][c] == 0) {
                    ++perim;
                }
                if (r == rows - 1 || grid[r + 1][c] == 0) {
                    ++perim;
                }
                if (c == 0 || grid[r][c - 1] == 0) {
                    ++perim;
                }
                if (c == cols - 1 || grid[r][c + 1] == 0) {
                    ++perim;
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
     *   R - The Number of Row in `grid`
     *   C - The Number of Column in `grid`
     *   - Time Complexity: O(R * C)
     *   - Space Complexity: O(1)
     */
    int solution2(vector<vector<int>>& grid) {
        int land = 0, shared = 0;

        for (size_t r = 0; r < grid.size(); ++r) {
            for (size_t c = 0; c < grid[r].size(); ++c) {
                if (grid[r][c] == 0) {
                    continue;
                }

                ++land;
                if (r > 0 && grid[r - 1][c] == 1) {
                    ++shared;
                }
                if (c > 0 && grid[r][c - 1] == 1) {
                    ++shared;
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
     *   R - The Number of Row in `grid`
     *   C - The Number of Column in `grid`
     *   - Time Complexity: O(R * C)
     *   - Space Complexity: O(R * C)
     */
    int dfs(vector<vector<int>>& g, int r, int c) {
        int rows = static_cast<int>(g.size());
        int cols = static_cast<int>(g[0].size());

        if (r < 0 || r >= rows || c < 0 || c >= cols || g[r][c] == 0) {
            return 1;
        }
        if (g[r][c] == 2) {
            return 0;
        }

        g[r][c] = 2;
        return dfs(g, r - 1, c) + dfs(g, r + 1, c) + dfs(g, r, c - 1) + dfs(g, r, c + 1);
    }

    int solution3(vector<vector<int>>& grid) {
        for (int r = 0; r < static_cast<int>(grid.size()); ++r) {
            for (int c = 0; c < static_cast<int>(grid[0].size()); ++c) {
                if (grid[r][c] == 1) {
                    return dfs(grid, r, c);
                }
            }
        }

        return 0;
    }
};
