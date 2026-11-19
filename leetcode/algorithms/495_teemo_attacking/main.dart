class TeemoAttacking {
  /**
   * Adjacent Gap Capping
   * 
   * Complexities:
   *   n - The Size of `timeSeries`
   *   - Time Complexity: O(n)
   *   - Space Complexity: O(1)
   */
  int findPoisonedDuration(List<int> timeSeries, int duration) {
    int total = 0;

    for (var i = 1; i < timeSeries.length; i++) {
      if (timeSeries[i] > timeSeries[i - 1] + duration) {
        total += duration;
      } else {
        total += timeSeries[i] - timeSeries[i - 1];
      }
    }

    return total + duration;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Adjacent Gap Capping
   * 
   * Complexities:
   *   n - The Size of `timeSeries`
   *   - Time Complexity: O(n)
   *   - Space Complexity: O(1)
   */
  int solution1(List<int> timeSeries, int duration) {
    var total = 0;

    for (var i = 0; i < timeSeries.length - 1; i++) {
      final gap = timeSeries[i + 1] - timeSeries[i];
      total += gap < duration ? gap : duration;
    }

    return total + duration;
  }

  /**
   * Solution 2
   * 
   * Interval Merging
   * 
   * Complexities:
   *   n - The Size of `timeSeries`
   *   - Time Complexity: O(n)
   *   - Space Complexity: O(1)
   */
  int solution2(List<int> timeSeries, int duration) {
    var total = 0;
    var end = 0;

    for (final t in timeSeries) {
      final newEnd = t + duration;

      if (t >= end) {
        total += duration;
      } else {
        total += newEnd - end;
      }

      end = newEnd;
    }

    return total;
  }

  /**
   * Solution 3
   * 
   * Simulation
   * 
   * Complexities:
   *   n - The Size of `timeSeries`
   *   m - `duration`
   *   - Time Complexity: O(n * m)
   *   - Space Complexity: O(n * m)
   */
  int solution3(List<int> timeSeries, int duration) {
    final poisoned = <int>{};

    for (final t in timeSeries) {
      for (var s = t; s < t + duration; s++) {
        poisoned.add(s);
      }
    }

    return poisoned.length;
  }
}
