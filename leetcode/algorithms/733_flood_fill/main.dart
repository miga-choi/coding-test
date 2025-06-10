class FloodFill {
  void fill(List<List<int>> image, int sr, int sc, int oldColor, int color) {
    if (sr < 0 || sc < 0 || sr >= image.length || sc >= image.first.length) {
      return;
    }

    if (image[sr][sc] != oldColor) {
      return;
    }

    image[sr][sc] = color;

    fill(image, sr + 1, sc, oldColor, color);
    fill(image, sr - 1, sc, oldColor, color);
    fill(image, sr, sc + 1, oldColor, color);
    fill(image, sr, sc - 1, oldColor, color);
  }

  List<List<int>> floodFill(List<List<int>> image, int sr, int sc, int color) {
    if (image[sr][sc] != color) {
      fill(image, sr, sc, image[sr][sc], color);
    }

    return image;
  }


  // Solution
  List<List<int>> solution(List<List<int>> image, int sr, int sc, int color) {
    final int value = image[sr][sc];

    if (value == color) {
      return image;
    }

    image[sr][sc] = color;

    if (sr != 0 && image[sr - 1][sc] == value) {
      floodFill(image, sr - 1, sc, color);
    }
    if (sc != 0 && image[sr][sc - 1] == value) {
      floodFill(image, sr, sc - 1, color);
    }
    if (sr != image.length - 1 && image[sr + 1][sc] == value) {
      floodFill(image, sr + 1, sc, color);
    }
    if (sc != image[0].length - 1 && image[sr][sc + 1] == value) {
      floodFill(image, sr, sc + 1, color);
    }

    return image;
  }
}
