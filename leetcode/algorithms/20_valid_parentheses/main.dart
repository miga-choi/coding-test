class ValidParentheses {
  /**
   * LIFO (Last-In, First-Out): Stack
   * 
   * Complexities:
   *   N - Length of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
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
   * 
   * Complexities:
   *   N - Length of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  bool solution(String s) {
    if (s.length % 2 != 0) {
      return false;
    }

    final Map<String, String> bracketMap = {
      ')': '(',
      '}': '{',
      ']': '['
    };

    final List<String> stack = [];

    for (int i = 0; i < s.length; i++) {
      String char = s[i];

      if (bracketMap.containsKey(char)) {
        if (stack.isEmpty) {
          return false;
        }

        String topElement = stack.removeLast();

        if (topElement != bracketMap[char]) {
          return false;
        }
      } else {
        stack.add(char);
      }
    }

    return stack.isEmpty;
  }
}
