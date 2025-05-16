class StudentAttendanceRecordI {
  public boolean checkRecord(String s) {
    if (s.length() - s.replaceAll("A", "").length() > 1) {
      return false;
    }

    for (int i = 0; i < s.length(); i++) {
      if (i > 1 &&
          s.charAt(i) == 'L' &&
          s.charAt(i - 1) == 'L' &&
          s.charAt(i - 2) == 'L') {
        return false;
      }
    }

    return true;
  }


  // Solution
  public boolean solution(String s) {
    int count = 0;

    for (int i = 0; i <= s.length() - 1; i++) {
      if (s.charAt(i) == 'A') {
        count++;
      }
    }

    for (int j = 0; j <= s.length() - 3; j++) {
      if (s.charAt(j) == 'L' && s.charAt(j + 1) == 'L' && s.charAt(j + 2) == 'L') {
        return false;
      }
    }

    if (count >= 2) {
      return false;
    }

    return true;
  }
}
