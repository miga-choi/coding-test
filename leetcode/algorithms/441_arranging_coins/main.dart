import 'dart:math';

class ArrangingCoins {
  int arrangeCoins(int n) {
    int level = 0;

    while (n - level > 0) {
      level += 1;
      n -= level;
    }

    return level;
  }


  // Solution
  // Solution 1
  int solution1(int n) {
    int sum = 0;

    for (int i = 1; i <= n; i++) {
      sum += i;
      if (sum > n) {
        return i - 1;
      } else if (sum == n) {
        return i;
      }
    }

    return 0;
  }

  // Solution 2: Iterative Approach
  int solution2(int n) {
    // which row we are on
    int i = 1;

    // checking to see if we have used all our coins
    while (n > 0) {
      // increasing our row
      i++;

      // adding coins to our row
      n = n - i;
    }

    // we return our current row minus one because the last row is our completed row
    return i - 1;
  }

  // Solution 3: Binary Search Approach
  int solution3(int n) {
    int left = 0;
    int right = n;

    while (left <= right) {
      int pivot = (left + (right - left) / 2).floor();
      int coinsUsed = (pivot * (pivot + 1) / 2).floor();
      if (coinsUsed == n) {
        return pivot;
      }
      if (n < coinsUsed) {
        right = pivot - 1;
      } else {
        left = pivot + 1;
      }
    }

    return right;
  }

  // Solution 4: Math Approach (using algebra)
  int solution4(int n) {
    return (sqrt(2 * n + 0.25) - 0.5).toInt();
  }

  // Solution 5: Math Approach (using Quadratic Formula)
  int bestSolution5(int n) {
    return ((-1 + (sqrt(1 + 8 * n))) / 2).toInt();
  }
}
