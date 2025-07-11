class RotateString {
  bool rotateString(String s, String goal) {
    return s.length == goal.length && (s + s).contains(goal);
  }


  // Solution: Brute-force
  bool solution(String s, String goal) {
    int n1 = s.length;
    int n2 = goal.length;

    if (n1 != n2) {
      return false;
    }

    for (int i = 0; i < n1; i++) {
      String check = s.substring(i) + s.substring(0, i);
      if (check == goal) {
        return true;
      }
    }

    return false;
  }
}
