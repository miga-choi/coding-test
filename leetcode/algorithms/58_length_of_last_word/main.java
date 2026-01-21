import java.util.ArrayList;
import java.util.List;

class LengthOfLastWord {
  /**
   * Reverse Traversal
   * 
   * Complexities:
   *   N - Length of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  public int lengthOfLastWord(String s) {
    String[] strArray = s.split(" ");
    List<String> resultArray = new ArrayList<>();

    for (String str : strArray) {
      if (str.isEmpty()) {
        continue;
      }
      resultArray.add(str);
    }

    return resultArray.get(resultArray.size() - 1).length();
  }


  // Solution
  /**
   * Solution 1
   * 
   * Reverse Traversal
   * 
   * Complexities:
   *   N - Length of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  public int solution1(String s) {
    int length = 0;
    int i = s.length() - 1;

    while (i >= 0 && s.charAt(i) == ' ') {
      i--;
    }

    while (i >= 0 && s.charAt(i) != ' ') {
      length++;
      i--;
    }

    return length;
  }

  /**
   * Solution 2
   * 
   * Built-in function
   * 
   * Complexities:
   *   N - Length of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  public int solution2(String s) {
    s = s.trim();

    int lastSpaceIndex = s.lastIndexOf(' ');

    return s.length() - lastSpaceIndex - 1;
  }
}
