class PrimeNumberOfSetBitsInBinaryRepresentation {
  bool isPrime(int n) {
    if (n < 2) {
      return false;
    }

    for (int i = 2; i < n; i++) {
      if (n % i == 0) {
        return false;
      }
    }

    return true;
  }

  int countPrimeSetBits(int left, int right) {
    int count = 0;

    for (int i = left; i <= right; i++) {
      int bits = 0;
      int n = i;

      while (n > 0) {
        bits += n % 2;
        n ~/= 2;
      }

      if (isPrime(bits)) {
        count++;
      }
    }

    return count;
  }


  // Solution
  int _bitCount(int n) {
    int count = 0;

    while (n > 0) {
      n &= (n - 1);
      count++;
    }

    return count;
  }

  int solution(int left, int right) {
    int count = 0;

    for (int i = left; i <= right; i++) {
      count += (665772 >> _bitCount(i)) & 1;
    }

    return count;
  }
}
