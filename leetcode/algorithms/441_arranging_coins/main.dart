import 'dart:math' as math; // sqrt

class ArrangingCoins {
  /**
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(√N)
   *   - Space Complexity: O(1)
   */
  int arrangeCoins(int n) {
    int level = 0;

    while (n - level > 0) {
      level += 1;
      n -= level;
    }

    return level;
  }


  // Solution
  /**
   * Solution 1
   *
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(√N)
   *   - Space Complexity: O(1)
   */
  int solution1(int n) {
    var row = 0;

    while (n > row) {
      row++;
      n -= row;
    }

    return row;
  }

  /**
   * Solution 2
   *
   * Binary Search
   *
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  int solution2(int n) {
    var left = 0;
    var right = n;

    while (left <= right) {
      final mid = left + (right - left) ~/ 2;
      final need = mid * (mid + 1) ~/ 2;

      if (need <= n) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return right;
  }

  /**
   * Solution 3
   *
   * Quadratic Formula
   *
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  int solution3(int n) {
    var k = ((math.sqrt(8 * n + 1) - 1) / 2).floor();

    while (k * (k + 1) ~/ 2 > n) {
      k--;
    }

    while ((k + 1) * (k + 2) ~/ 2 <= n) {
      k++;
    }

    return k;
  }
}
