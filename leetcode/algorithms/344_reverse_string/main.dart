class ReverseString {
  void reverseString(List<String> s) {
    for (int i = 0; i < s.length / 2; i++) {
      String temp = s[i];
      s[i] = s[s.length - i - 1];
      s[s.length - i - 1] = temp;
    }
  }


  // Solution
  // Solution 1
  void solution1(List<String> s) {
    s.setRange(0, s.length, s.reversed);
  }

  // Solution 2
  void solution2(List<String> s) {
    // Initialize a variable `left` to 0, which represents the left index of the list
    int left = 0;

    // Initialize a variable `right` to `s.length - 1`, which represents the right index of the list
    int right = s.length - 1;

    // Start a `while` loop that iterates as long as `left` is less than `right`
    while (left < right) {
      // Store the value at index `left` in a temporary variable `tmp`
      String tmp = s[left];

      // Overwrite the value at index `left` with the value at index `right`
      s[left] = s[right];

      // Overwrite the value at index `right` with the value stored in `tmp`
      s[right] = tmp;

      // Increment `left` by 1
      left++;

      // Decrement `right` by 1
      right--;
    }
  }
}
