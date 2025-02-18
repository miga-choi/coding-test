import "dart:math";

class DistributeCandies {
  int distributeCandies(List<int> candyType) {
    return min(candyType.toSet().length, candyType.length ~/ 2);
  }

  // Solution
  int solution(List<int> candyType) {
    // Length divided by two
    int n = candyType.length ~/ 2;

    // Taking unique values by converting to set
    Set<int> s = candyType.toSet();

    // if (n < s.length) { return n; } else { return s.length; }
    return n < s.length ? n : s.length;
  }
}
