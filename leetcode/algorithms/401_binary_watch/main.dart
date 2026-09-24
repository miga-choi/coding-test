class BinaryWatch {
  /**
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  List<String> readBinaryWatch(int turnedOn) {
    List<String> result = List<String>.empty(growable: true);

    // Hour
    for (int h = 0; h < 12; h++) {
      int hBitCount = h.toRadixString(2).replaceAll("0", "").length;

      // Minute
      for (int m = 0; m < 60; m++) {
        int mBitCount = m.toRadixString(2).replaceAll("0", "").length;

        // Count
        if (hBitCount + mBitCount == turnedOn) {
          result.add(m < 10 ? "$h:0$m" : "$h:$m");
        }
      }
    }

    return result;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  int _popCount(int x) {
    var count = 0;

    while (x != 0) {
      x &= x - 1;
      count++;
    }

    return count;
  }

  List<String> solution1(int turnedOn) {
    final res = <String>[];

    for (var h = 0; h < 12; h++) {
      for (var m = 0; m < 60; m++) {
        if (_popCount(h) + _popCount(m) == turnedOn) {
          res.add('$h:${m.toString().padLeft(2, '0')}');
        }
      }
    }

    return res;
  }

  /**
   * Solution 2
   * 
   * 10-Bitmask
   * 
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  List<String> solution2(int turnedOn) {
    final res = <String>[];

    for (var mask = 0; mask < 1024; mask++) {
      final h = mask >> 6;
      final m = mask & 0x3F;

      if (h < 12 && m < 60 && _popCount(mask) == turnedOn) {
        res.add('$h:${m.toString().padLeft(2, '0')}');
      }
    }

    return res;
  }

  /**
   * Solution 3
   * 
   * Backtracking
   * 
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  List<String> solution3(int turnedOn) {
    final res = <String>[];

    void dfs(int start, int remaining, int h, int m) {
      if (h > 11 || m > 59) {
        return;
      }

      if (remaining == 0) {
        res.add('$h:${m.toString().padLeft(2, '0')}');
        return;
      }

      for (var i = start; i < 10; i++) {
        if (i < 4) {
          dfs(i + 1, remaining - 1, h | (1 << i), m);
        } else {
          dfs(i + 1, remaining - 1, h, m | (1 << (i - 4)));
        }
      }
    }

    dfs(0, turnedOn, 0, 0);

    return res;
  }
}
