class ValidParentheses {
  bool isValid(String s) {
    List<String> stack = <String>[];

    for (String c in s.split("")) {
      switch (c) {
        case "(":
          stack.add(")");
          break;
        case "[":
          stack.add("]");
          break;
        case "{":
          stack.add("}");
          break;
        default:
          if (stack.length == 0 || !(stack.removeLast() == c)) {
            return false;
          }
      }
    }

    return stack.length <= 0;
  }

  // Best Solution
  bool bestSolution(String s) {
    String d1 = "()";
    String d2 = "{}";
    String d3 = "[]";
    while (s.isNotEmpty) {
      if (s.contains(d1)) {
        s = s.replaceAll(d1, '');
      } else if (s.contains(d2)) {
        s = s.replaceAll(d2, '');
      } else if (s.contains(d3)) {
        s = s.replaceAll(d3, '');
      } else {
        return false;
      }
    }
    return true;
  }
}
