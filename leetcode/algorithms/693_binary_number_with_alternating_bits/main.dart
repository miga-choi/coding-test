class BinaryNumberWithAlternatingBits {
  bool hasAlternatingBits(int n) {
    int prev = -1;

    while (n > 0) {
      if (n % 2 == prev) {
        return false;
      }
      prev = n % 2;
      n >>= 1;
    }

    return true;
  }


  // Solution
  // Solution 1
  bool solution1(int n) {
    n = n ^ (n >> 1);
    return (n & (n + 1)) == 0;
  }

  // Solution 2
  bool solution2(int n) {
    List<String> list = n.toRadixString(2).split("");

    for (int i = 0; i < list.length - 1; i++) {
      if (list[i] == list[i + 1]) {
        return false;
      }
    }

    return true;
  }
}
