import 'dart:math';

class SqrtX {
  /**
   * Built-in function
   * 
   * Complexities:
   *   N - Value of `x`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  int mySqrt(int x) {
    return sqrt(x).floor();
  }


  // Solution
  /**
   * Solution 1
   * 
   * Binary Search
   * 
   * Complexities:
   *   N - Value of `x`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  int solution1(int x) {
    if (x == 0) {
      return 0;
    }

    int low = 1;
    int high = x;

    while (low <= high) {
      int mid = low + (high - low) ~/ 2;

      int square = mid * mid;

      if (square == x) {
        return mid;
      } else if (square < x) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return high;
  }

  /**
   * Solution 2
   * 
   * Newton-Raphson Method
   * 
   * Complexities:
   *   N - Value of `x`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  int solution2(int x) {
    if (x == 0) {
      return 0;
    }

    double r = x.toDouble();

    while ((r * r - x).abs() > 0.1) {
      r = (r + x / r) / 2;
    }

    return r.toInt();
  }
}
