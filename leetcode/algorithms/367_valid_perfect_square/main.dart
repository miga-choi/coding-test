class ValidPerfectSquare {
  /**
   * Complexities:
   *   N - `num`
   *   - Time Complexity: O(√N)
   *   - Space Complexity: O(1)
   */
  bool isPerfectSquare(int num) {
    if (num > 1) {
      for (int i = 0; i < num; i++) {
        if (i * i > num) {
          return false;
        } else if (i * i == num) {
          break;
        }
      }
    }

    return true;
  }


  // Solution
  /**
   * Solution 1
   *
   * Binary Search
   *
   * Complexities:
   *   N - `num`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  bool solution1(int num) {
    var left = 1;
    var right = num;

    while (left <= right) {
      final mid = left + (right - left) ~/ 2;
      final square = mid * mid;

      if (square == num) {
        return true;
      } else if (square < num) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return false;
  }

  /**
   * Solution 2
   *
   * Sum of Odd Numbers
   *
   * Complexities:
   *   N - `num`
   *   - Time Complexity: O(√N)
   *   - Space Complexity: O(1)
   */
  bool solution2(int num) {
    var odd = 1;

    while (num > 0) {
      num -= odd;
      odd += 2;
    }

    return num == 0;
  }

  /**
   * Solution 3
   *
   * Newton-Raphson Method
   *
   * Complexities:
   *   N - `num`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  bool solution3(int num) {
    var x = num;

    while (x * x > num) {
      x = (x + num ~/ x) ~/ 2;
    }

    return x * x == num;
  }
}
