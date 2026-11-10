/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */
class VersionControl {
  bool isBadVersion(int version) {
    return false;
  }
}

class FirstBadVersion extends VersionControl {
  // Solution
  /**
   * Solution 1
   * 
   * Lower Bound Binary Search
   * 
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  int solution1(int n) {
    var left = 1;
    var right = n;

    while (left < right) {
      final mid = left + (right - left) ~/ 2;

      if (isBadVersion(mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }

  /**
   * Solution 2
   * 
   * Closed-Interval Binary Search with Answer Tracking
   * 
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  int solution2(int n) {
    var left = 1;
    var right = n;
    var answer = n;

    while (left <= right) {
      final mid = left + (right - left) ~/ 2;

      if (isBadVersion(mid)) {
        answer = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return answer;
  }

  /**
   * Solution 3
   * 
   * Linear Scan
   * 
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution3(int n) {
    for (var v = 1; v <= n; v++) {
      if (isBadVersion(v)) {
        return v;
      }
    }

    return n;
  }
}
