import 'dart:math';

class LongestUncommonSubsequenceI {
  int findLUSlength(String a, String b) {
    if (a == b) {
      return -1;
    }
    return max(a.length, b.length);
  }

  // Solution
  int solution(String a, String b) {
    return a == b ? -1 : max(a.length, b.length);
  }
}
