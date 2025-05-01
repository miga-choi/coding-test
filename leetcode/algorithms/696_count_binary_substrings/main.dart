import 'dart:math';

class CountBinarySubstrings {
  int countBinarySubstrings(String s) {
    int count = 1;
    int prevCount = 0;
    int result = 0;

    for (int i = 1; i < s.length; i++) {
      if (s[i] == s[i - 1]) {
        count++;
      } else {
        result += min(count, prevCount);
        prevCount = count;
        count = 1;
      }
    }

    return result + min(count, prevCount);
  }
}
