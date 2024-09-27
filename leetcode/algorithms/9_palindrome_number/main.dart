class PalindromeNumber {
  bool isPalindrome(int x) {
    if (x < 0) return false;

    final List<String> xList = x.toString().split("");
    for (var i = 0; i < xList.length / 2; i++) {
      if (xList[i] != xList[xList.length - 1 - i]) return false;
    }

    return true;
  }

  // Best Solution
  bool bestSolution(int x) {
    int reverse = 0;
    int copy = x;

    // The loop break when the copy of original number becomes zero
    // Also negative number cannot be a palindrome
    while (copy > 0) {
      final digit = copy % 10;
      reverse = reverse * 10 + digit;
      copy = copy ~/ 10;
    }

    return reverse == x;
  }
}
