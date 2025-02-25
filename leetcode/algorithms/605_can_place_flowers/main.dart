class CanPlaceFlowers {
  bool canPlaceFlowers(List<int> flowerbed, int n) {
    if (flowerbed.length == 1) {
      return flowerbed.first == 0 || n == 0;
    }
    for (int i = 0; i < flowerbed.length && n > 0; i++) {
      if (i == 0) {
        if (flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
          flowerbed[i] = 1;
          n--;
        }
      } else if (i == flowerbed.length - 1) {
        if (flowerbed[i - 1] == 0 && flowerbed[i] == 0) {
          flowerbed[i] = 1;
          n--;
        }
      } else {
        if (flowerbed[i - 1] == 0 &&
            flowerbed[i] == 0 &&
            flowerbed[i + 1] == 0) {
          flowerbed[i] = 1;
          n--;
        }
      }
    }
    return n == 0;
  }

  // Solution
  bool solution(List<int> flowerbed, int n) {
    int len = flowerbed.length;
    for (int i = 0; i < len; i++) {
      bool left = i == 0 || flowerbed[i - 1] == 0;
      bool right = i == len - 1 || flowerbed[i + 1] == 0;
      if (left && right && flowerbed[i] == 0) {
        flowerbed[i] = 1;
        n--;
      }
    }
    return n <= 0;
  }
}
