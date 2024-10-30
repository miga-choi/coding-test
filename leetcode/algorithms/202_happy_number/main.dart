class HappyNumber {
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

  // Best Solution
  int getNext(int n) {
    int totalSum = 0;
    while (n > 0) {
      int d = n % 10;
      n = n ~/ 10;
      totalSum += d * d;
    }
    return totalSum;
  }

  bool bestSolution(int n) {
    while (n != 1 && n != 4) n = getNext(n);
    return n == 1;
  }
}
