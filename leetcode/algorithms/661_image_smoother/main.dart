class ImageSmoother {
  List<List<int>> imageSmoother(List<List<int>> img) {
    int xLen = img.length;
    int yLen = img.first.length;
    List<List<int>> result = List<List<int>>.generate(
      xLen,
      (int index) => List<int>.filled(yLen, 0),
    );

    for (int i = 0; i < xLen; i++) {
      for (int j = 0; j < yLen; j++) {
        int sum = 0;
        int count = 0;
        for (int k = -1; k < 2; k++) {
          int x = i + k;
          for (int l = -1; l < 2; l++) {
            int y = j + l;
            if (x < 0 || x >= xLen || y < 0 || y >= yLen) {
              continue;
            }
            sum += img[x][y];
            count++;
          }
        }
        result[i][j] = sum ~/ count;
      }
    }

    return result;
  }
}
