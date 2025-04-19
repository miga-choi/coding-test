class CountingBits {
  List<int> countBits(int n) {
    List<int> result = List<int>.filled(n + 1, 0);

    for (int i = 0; i <= n; i++) {
      int sum = 0;
      int num = i;
      while (num > 0) {
        if (num % 2 == 1) {
          sum++;
        }
        num = (num / 2).floor();
      }
      result[i] = sum;
    }

    return result;
  }


  // Solution
  List<int> solution(int n) {
    List<int> result = List.filled(n + 1, 0);

    for (int i = 1; i <= n; i++) {
      result[i] = result[i >> 1] + (i & 1);
    }

    return result;
  }
}
