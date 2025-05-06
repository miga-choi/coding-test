class IslandPerimeter {
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
    public int solution(int[][] grid) {
        int islands = 0, neighbours = 0;

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    // count islands
                    islands++;

                    if (i < grid.length - 1 && grid[i + 1][j] == 1) {
                        // count down neighbours
                        neighbours++;
                    }

                    if (j < grid[i].length - 1 && grid[i][j + 1] == 1) {
                        // count right neighbours
                        neighbours++;
                    }
                }
            }
        }

        return islands * 4 - neighbours * 2;
    }
}
