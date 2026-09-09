class GuessNumberHigherOrLower {
  /**
   * Forward declaration of guess API.
   * 
   * @param num your guess
   * @return -1 if num is higher than the picked number
   *         1 if num is lower than the picked number
   *         otherwise return 0
   * 
   *         int guess(int num);
   */
  int guess(int num) {
    return 0;
  }

  /**
   * Binary Search
   *
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  int guessNumber(int n) {
    int left = 0;
    int right = n;
    int mid = n ~/ 2;

    while (left <= right) {
      mid = (left + right) ~/ 2;

      if (guess(mid) > 0) {
        left = mid + 1;
      } else if (guess(mid) < 0) {
        right = mid - 1;
      } else {
        break;
      }
    }

    return mid;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Binary Search
   *
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  int solution1(int n) {
    var left = 1;
    var right = n;

    while (left <= right) {
      final mid = left + (right - left) ~/ 2;
      final res = guess(mid);

      if (res == 0) {
        return mid;
      } else if (res < 0) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return -1;
  }

  /**
   * Solution 2
   *
   * Recursion
   *
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(logᴺ)
   */
  int search(int left, int right) {
    if (left > right) {
      return -1;
    }

    final mid = left + (right - left) ~/ 2;
    final res = guess(mid);

    if (res == 0) {
      return mid;
    }

    return res < 0 ? search(left, mid - 1) : search(mid + 1, right);
  }

  int solution2(int n) {
    return search(1, n);
  }
}
