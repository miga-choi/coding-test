class PlusOne {
  /**
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  List<int> plusOne(List<int> digits) {
    for (int i = digits.length - 1; i >= 0; i--) {
      digits[i]++;

      if (digits[i] < 10) {
        return digits;
      }

      digits[i] -= 10;
    }

    return [1] + List.filled(digits.length, 0);
  }


  // Solution
  /**
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  List<int> solution(List<int> digits) {
    int n = digits.length;

    for (int i = n - 1; i >= 0; i--) {
      digits[i]++;

      if (digits[i] < 10) {
        return digits;
      }

      digits[i] = 0;
    }

    digits.insert(0, 1);

    return digits;
  }
}
