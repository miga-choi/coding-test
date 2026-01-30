class SqrtX {
  /**
   * Binary Search
   * 
   * Complexities:
   *   N - Value of `x`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  public int mySqrt(int x) {
    if (x == 0) {
      return 0;
    }

    int low = 1;
    int high = x;

    while (low <= high) {
      int mid = (low + high) / 2;
      if (mid == x / mid) {
        return mid;
      } else if (mid > x / mid) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return high;
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
  public int solution1(int x) {
    if (x == 0) {
      return 0;
    }

    int left = 1;
    int right = x;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      long square = (long) mid * mid;

      if (square == x) {
        return mid;
      } else if (square < x) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return right;
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
  public int solution2(int x) {
    long r = x;

    while (r * r > x) {
      r = (r + x / r) / 2;
    }

    return (int) r;
  }
}
