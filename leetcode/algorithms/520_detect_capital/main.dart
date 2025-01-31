import 'dart:convert';

class DetectCapital {
  bool detectCapitalUse(String word) {
    return RegExp(r"^([A-Z]+$|[a-z]+$|[A-Z][a-z]*$)").hasMatch(word);
  }

  // Solution
  bool solution(String word) {
    int cnt = 0;
    for (int c in ascii.encode(word)) {
      if (90 - c >= 0) {
        cnt++;
      }
    }
    return (cnt == 0 || cnt == word.length) ||
        (cnt == 1 && 90 - word.codeUnitAt(0) >= 0);
  }
}
