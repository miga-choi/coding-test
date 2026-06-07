class HappyNumber {
  /**
   * Floyd's Cycle-Finding Algorithm
   *
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  int sum(int n) {
    int sum = 0;
    while (n > 0) {
      sum += (n % 10) * (n % 10);
      n = (n / 10).floor();
    }
    return sum;
  }

  bool isHappy(int n) {
    int fast = n;
    int slow = n;

    while (true) {
      slow = sum(slow);
      fast = sum(sum(fast));
      if (fast == 1) {
        break;
      }
      if (fast == slow) {
        return false;
      }
    }

    return true;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Floyd's Cycle-Finding Algorithm
   *
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  int _getNext1(int n) {
    int totalSum = 0;

    while (n > 0) {
      int digit = n % 10;
      n = n ~/ 10;
      totalSum += digit * digit;
    }

    return totalSum;
  }

  bool solution1(int n) {
    int slow = n;
    int fast = _getNext1(n);

    while (fast != 1 && slow != fast) {
      slow = _getNext1(slow);
      fast = _getNext1(_getNext1(fast));
    }

    return fast == 1;
  }

  /**
   * Solution 2
   * 
   * Hash Set
   *
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(logᴺ)
   */
  int _getNext2(int n) {
    int totalSum = 0;

    while (n > 0) {
      int digit = n % 10;
      n = n ~/ 10;
      totalSum += digit * digit;
    }

    return totalSum;
  }

  bool solution2(int n) {
    final Set<int> seen = {};

    while (n != 1 && !seen.contains(n)) {
      seen.add(n);
      n = _getNext2(n);
    }

    return n == 1;
  }
}
