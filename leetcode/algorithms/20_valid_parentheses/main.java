import java.util.Stack;

class ValidParentheses {
  /**
   * LIFO (Last-In, First-Out): Stack
   * 
   * Complexities:
   *   N - Length of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  public boolean isValid(String s) {
    Stack<String> stack = new Stack<>();

    for (String c : s.split("")) {
      switch (c) {
        case "(" -> stack.push(")");
        case "[" -> stack.push("]");
        case "{" -> stack.push("}");
        default -> {
          if (stack.empty() || !stack.pop().equals(c)) {
            return false;
          }
        }
      }
    }

    return stack.empty();
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
  public boolean solution(String s) {
    if (s.length() % 2 != 0) {
      return false;
    }

    Stack<Character> stack = new Stack<>();

    for (char c : s.toCharArray()) {
      switch (c) {
        case '(' -> stack.push(')');
        case '{' -> stack.push('}');
        case '[' -> stack.push(']');
        default -> {
          if (stack.isEmpty() || stack.pop() != c) {
            return false;
          }
        }
      }
    }

    return stack.isEmpty();
  }
}
