class IsSubsequence {
  bool isSubsequence(String s, String t) {
    if (s.length == 0) {
      return true;
    }

    List<String> sArray = s.split("");
    int i = 0;

    for (String c in t.split("")) {
      if (c == sArray[i]) {
        i++;
      }
      if (i == sArray.length) {
        break;
      }
    }

    return i == s.length;
  }

  // Best Solution
  bool bestSolution(String s, String t) {
    int index = 0;
    int pointer = 0;

    while (index < s.length && pointer < t.length) {
      if (s[index] == t[pointer]) {
        index++;
      }
      pointer++;
    }

    return index == s.length;
  }
}
