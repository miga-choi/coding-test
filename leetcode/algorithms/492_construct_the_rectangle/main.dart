import 'dart:math'; // sqrt

class ConstructTheRectangle {
  /**
   * Divisor Scan up to Square Root
   * 
   * Complexities:
   *   n - `area`
   *   - Time Complexity: O(√n)
   *   - Space Complexity: O(1)
   */
  List<int> constructRectangle(int area) {
    for (int i = sqrt(area).toInt(); i > 0; i--) {
      if (area % i == 0) {
        return [area ~/ i, i];
      }
    }

    return [area, 1];
  }


  // Solution
  /**
   * Solution 1
   * 
   * Square Root Descent
   * 
   * Complexities:
   *   n - `area`
   *   - Time Complexity: O(√n)
   *   - Space Complexity: O(1)
   */
  List<int> solution1(int area) {
    var w = sqrt(area).floor();

    while (w * w > area) {
      w--;
    }

    while ((w + 1) * (w + 1) <= area) {
      w++;
    }

    while (area % w != 0) {
      w--;
    }

    return [area ~/ w, w];
  }

  /**
   * Solution 2
   * 
   * Divisor Scan up to Square Root
   * 
   * Complexities:
   *   n - `area`
   *   - Time Complexity: O(√n)
   *   - Space Complexity: O(1)
   */
  List<int> solution2(int area) {
    var best = 1;

    for (var w = 1; w * w <= area; w++) {
      if (area % w == 0) {
        best = w;
      }
    }

    return [area ~/ best, best];
  }

  /**
   * Solution 3
   * 
   * Brute Force
   * 
   * Complexities:
   *   n - `area`
   *   - Time Complexity: O(n)
   *   - Space Complexity: O(1)
   */
  List<int> solution3(int area) {
    for (var l = 1; l <= area; l++) {
      if (area % l == 0 && l >= area ~/ l) {
        return [l, area ~/ l];
      }
    }

    return [area, 1];
  }
}
