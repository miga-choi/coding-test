class NumberComplement {
  int findComplement(int num) {
    int startsWithZeroCount = 0;
    int zeroCountDone = 0;

    int reverseNum = 0;
    while (num > 0) {
      if (zeroCountDone == 0) {
        if ((num & 1) > 0) {
          startsWithZeroCount++;
        } else {
          zeroCountDone = 1;
        }
      }

      reverseNum = (reverseNum << 1) | (num & 1 ^ 1);
      num >>= 1;
    }

    int result = 0;
    while (reverseNum > 0) {
      result = (result << 1) | (reverseNum & 1);
      reverseNum >>= 1;
    }

    return result << startsWithZeroCount;
  }


  // Solution
  // Solution 1
  int solution1(int num) {
    String onescomplement = '';

    var bynarynum = '';

    bynarynum = num.toRadixString(2);

    for (int i = 0; i < bynarynum.length; i++) {
      if (bynarynum[i] == '0') {
        onescomplement += '1';
      } else if (bynarynum[i] == '1') {
        onescomplement += '0';
      }
    }

    int val = int.parse(onescomplement, radix: 2);

    return val;
  }

  // Solution 2
  int solution2(int num) {
    final int mask = (1 << num.bitLength) - 1;
    return num ^ mask;
  }
}
