class SelfDividingNumbers {
  List<int> selfDividingNumbers(int left, int right) {
    final List<int> result = List.empty(growable: true);

    for (int i = left; i <= right; i++) {
      int v = i;

      while (v > 0) {
        if (v % 10 == 0 || i % (v % 10) > 0) {
          break;
        }

        v ~/= 10;
      }

      if (v == 0) {
        result.add(i);
      }
    }

    return result;
  }


  // Solution
  bool isSelfDividing(int num) {
    String numStr = num.toString();

    for (int i = 0; i < numStr.length; i++) {
      int digit = int.parse(numStr[i]);

      if (digit == 0 || num % digit != 0) {
        return false;
      }
    }

    return true;
  }

  List<int> solution(int left, int right) {
    List<int> res = [];

    for (int i = left; i <= right; i++) {
      if (isSelfDividing(i)) {
        res.add(i);
      }
    }

    return res;
  }
}
