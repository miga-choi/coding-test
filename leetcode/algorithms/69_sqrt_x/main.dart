import 'dart:math';

class SqrtX {
  int mySqrt(int x) {
    return sqrt(x).floor();
  }

  // Best Solution
  int bestSolution(int x) {
    int base = 2;
    if (x <= 1) return x == 1 ? 1 : 0;
    while (base * base <= x) {
      base++;
    }
    return base - 1;
  }
}
