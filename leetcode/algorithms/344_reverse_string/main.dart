class ReverseString {
  /**
   * Two pointers
   *
   * Complexities:
   *   N - The size of `s`
   *   - Time Complexities: O(N)
   *   - Space Complexities: O(1)
   */
  void reverseString(List<String> s) {
    for (int i = 0; i < s.length / 2; i++) {
      String temp = s[i];
      s[i] = s[s.length - i - 1];
      s[s.length - i - 1] = temp;
    }
  }


  // Solution
  /**
   * Solution 1
   *
   * Two pointers
   *
   * Complexities:
   *   N - The size of `s`
   *   - Time Complexities: O(N)
   *   - Space Complexities: O(1)
   */
  void solution1(List<String> s) {
    var left = 0;
    var right = s.length - 1;

    while (left < right) {
      final tmp = s[left];
      s[left] = s[right];
      s[right] = tmp;
      left++;
      right--;
    }
  }

  /**
   * Solution 2
   *
   * Recursion
   *
   * Complexities:
   *   N - The size of `s`
   *   - Time Complexities: O(N)
   *   - Space Complexities: O(N)
   */
  void solution2(List<String> s, [int left = 0, int? right]) {
    right ??= s.length - 1;

    if (left >= right) {
      return;
    }

    final tmp = s[left];
    s[left] = s[right];
    s[right] = tmp;

    solution2(s, left + 1, right - 1);
  }
}
