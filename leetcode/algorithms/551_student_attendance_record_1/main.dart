class StudentAttendanceRecordI {
  bool checkRecord(String s) {
    final List<String> sArray = s.split("");
    int absent = 0;

    for (int i = 0; i < sArray.length; i++) {
      if (sArray[i] == "A") {
        if (++absent > 1) {
          return false;
        }
      } else if (i > 1 &&
          sArray[i - 2] == 'L' &&
          sArray[i - 1] == 'L' &&
          sArray[i] == 'L') {
        return false;
      }
    }

    return true;
  }

  // Solution
  bool solution(String s) {
    int a = 0;
    for (int i = 0; i < s.length; i++) {
      if (s[i] == "A") {
        a++;
      }
      if (i > 0 && i < s.length - 1 && s[i] == "L") {
        if (s[i - 1] == "L" && s[i + 1] == "L") {
          return false;
        }
      }
    }
    return a < 2;
  }
}
