class OneBitAndTwoBitCharacters {
  bool isOneBitCharacter(List<int> bits) {
    int i = 0;

    while (i < bits.length - 1) {
      if (bits[i] == 1) {
        i += 2;
      } else {
        i += 1;
      }
    }

    return i == bits.length - 1;
  }


  // Solution
  // Solution 1: Increment Pointer
  bool solution1(List<int> bits) {
    int i = 0;

    while (i < bits.length - 1) {
      i += bits[i] + 1;
    }

    return i == bits.length - 1;
  }

  // Solution 2: Greedy
  bool solution2(List<int> bits) {
    int i = bits.length - 2;

    while (i >= 0 && bits[i] > 0) {
      i--;
    }

    return (bits.length - i) % 2 == 0;
  }
}
