class RepeatedSubstringPattern {
  bool repeatedSubstringPattern(String s) {
    return (s + s).substring(1, s.length * 2 - 1).contains(s);
  }


  // Solution
  bool solution(String s) {
    return (s + s).substring(1, s.length * 2 - 1).contains(s);
  }
}
