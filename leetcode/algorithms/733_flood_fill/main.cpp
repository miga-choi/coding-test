#include<vector>
using namespace std;

class FloodFill {
public:
    void fill(
      vector<vector<int>>& image,
      int sr, int sc,
      int color, int newColor
    ) {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()) {
            return;
        }

        if (image[sr][sc] != color) {
            return;
        }

        image[sr][sc] = newColor;

        fill(image, sr - 1, sc, color, newColor);
        fill(image, sr + 1, sc, color, newColor);
        fill(image, sr, sc - 1, color, newColor);
        fill(image, sr, sc + 1, color, newColor);
    }

    vector<vector<int>> floodFill(
      vector<vector<int>>& image,
      int sr, int sc,
      int color
    ) {
        if (image[sr][sc] != color) {
            fill(image, sr, sc, image[sr][sc], color);
        }

        return image;
    }


    // Solution
    void dfs(
        vector<vector<int>>& image,
        int i, int j,
        int val, int newColor
    ) {
        if (
            i < 0 || i >= image.size() ||
            j < 0 || j >= image[0].size() ||
            image[i][j] == newColor || image[i][j] != val
        ) {
            return;
        }
        
        image[i][j] = newColor;

        dfs(image, i - 1, j, val, newColor);
        dfs(image, i + 1, j, val, newColor);
        dfs(image, i, j - 1, val, newColor);
        dfs(image, i, j + 1, val, newColor);
    }

    vector<vector<int>> floodFill(
        vector<vector<int>>& image,
        int sr, int sc,
        int newColor
    ) {
        int val = image[sr][sc];

        dfs(image, sr, sc, val, newColor);

        return image;
    }
};
