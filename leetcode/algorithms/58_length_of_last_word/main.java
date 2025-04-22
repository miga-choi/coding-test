import java.util.ArrayList;
import java.util.List;

class LengthOfLastWord {
  public int lengthOfLastWord(String s) {
    String[] sArray = s.split(" ");
    List<String> resultArray = new ArrayList<String>();
    for (int i = 0; i < sArray.length; i++) {
      if (sArray[i].isEmpty()) {
        continue;
      }
      resultArray.add(sArray[i]);
    }
    return resultArray.get(resultArray.size() - 1).length();
  }


  // Solution
  // Solution 1
  public int solution1(String s) {
    int length = 0;

    // We are looking for the last word so let's go backward
    for (int i = s.length() - 1; i >= 0; i--) {
      if (s.charAt(i) != ' ') {
        // a letter is found so count
        length++;
      } else {
        // it's a white space instead
        if (length > 0) {
          // Did we already started to count a word ? Yes so we found the last word
          return length;
        }
      }
    }
    return length;
  }

  // Solution 2
  public int solution2(String s) {
    return s.trim().length() - s.trim().lastIndexOf(" ") - 1;
  }

  // Solution 3
  public int solution3(String s) {
    s = s.trim();
    int lastIndex = s.lastIndexOf(' ') + 1;
    return s.length() - lastIndex;
  }
}
