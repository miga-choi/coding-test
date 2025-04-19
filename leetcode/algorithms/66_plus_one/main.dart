class PlusOne {
  List<int> plusOne(List<int> digits) {
    int up = 1;

    for (int i = digits.length - 1; i >= 0; i--) {
      int num = digits[i] + up;
      if (num >= 10) {
        num -= 10;
        up = 1;
      } else {
        up = 0;
      }

      digits[i] = num;
    }

    if (up > 0) {
      digits.insert(0, 1);
    }

    return digits;
  }


  // Solution
  List<int> solution(List<int> digits) {
    for (int i = digits.length - 1; i >= 0; i--) {
      if (digits[i] < 9) {
        digits[i]++;
        return digits;
      }
      digits[i] = 0;
    }
    digits.insert(0, 1);
    return digits;
  }
}
