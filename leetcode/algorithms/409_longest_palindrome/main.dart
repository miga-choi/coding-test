class LongestPalindrome {
  int longestPalindrome(String s) {
    int freq = 0;

    for (String c in s.split('')) {
      freq ^= (1 << (c.codeUnitAt(0) - 'A'.codeUnitAt(0)));
    }

    int hasOdd = 0;

    for (int i = 0; i <= 'z'.codeUnitAt(0) - 'A'.codeUnitAt(0); i++) {
      if (((freq >> i) & 1) == 1) {
        hasOdd++;
      }
    }

    return hasOdd > 1 ? s.length - hasOdd + 1 : s.length;
  }

  // Best Solution
  int bestSolution(String s) {
    Set<String> se = {};
    int palindrome = 0;
    for (var char in s.split('')) {
      if (se.contains(char)) {
        se.remove(char);
        palindrome += 2;
      } else {
        se.add(char);
      }
    }
    if (se.isNotEmpty) {
      palindrome++;
    }
    return palindrome;
  }
}
