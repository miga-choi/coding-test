import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

class ValidParentheses {
  /**
   * LIFO (Last-In, First-Out): Stack
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
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
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
  public boolean solution(String s) {
    Map<Character, Character> mappings = new HashMap<>();
    mappings.put(')', '(');
    mappings.put('}', '{');
    mappings.put(']', '[');

    Stack<Character> stack = new Stack<>();

    for (char c : s.toCharArray()) {
      if (mappings.containsKey(c)) {
        char topElement = stack.isEmpty() ? '#' : stack.pop();

        if (topElement != mappings.get(c)) {
          return false;
        }
      } else {
        stack.push(c);
      }
    }

    return stack.isEmpty();
  }
}
