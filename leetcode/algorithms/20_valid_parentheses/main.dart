class ValidParentheses {
  /**
   * LIFO (Last-In, First-Out): Stack
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
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
          if (stack.isEmpty || stack.removeLast() != c) {
            return false;
          }
      }
    }

    return stack.isEmpty;
  }


  // Solution
  /**
   * LIFO (Last-In, First-Out): Stack
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
  bool solution(String s) {
    if (s.length % 2 != 0) {
      return false;
    }

    List<String> stack = [];

    final Map<String, String> bracketPairs = {'(': ')', '{': '}', '[': ']'};

    for (int i = 0; i < s.length; i++) {
      String char = s[i];

      if (bracketPairs.containsKey(char)) {
        stack.add(char);
      } else {
        if (stack.isEmpty) {
          return false;
        }

        String lastOpen = stack.removeLast();
        if (bracketPairs[lastOpen] != char) {
          return false;
        }
      }
    }

    return stack.isEmpty;
  }
}
