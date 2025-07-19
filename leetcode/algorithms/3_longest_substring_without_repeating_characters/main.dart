import 'dart:math';

class LongestSubstringWithoutRepeatingCharacters {
  int lengthOfLongestSubstring(String s) {
    List<int> charMap = List<int>.filled(128, -1);
    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < s.length; right++) {
      int currentCharCode = s.codeUnitAt(right);

      if (charMap[currentCharCode] >= left) {
        left = charMap[currentCharCode] + 1;
      }

      charMap[currentCharCode] = right;

      maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
  }


  // Solution
  // Solution 1: Set
  int solution1(String s) {
    int n = s.length;
    int maxLength = 0;
    Set<String> charSet = Set<String>();
    int left = 0;

    for (int right = 0; right < n; right++) {
      if (!charSet.contains(s[right])) {
        charSet.add(s[right]);
        maxLength = max(maxLength, right - left + 1);
      } else {
        while (charSet.contains(s[right])) {
          charSet.remove(s[left]);
          left++;
        }
        charSet.add(s[right]);
      }
    }

    return maxLength;
  }

  // Solution 2: Map
  int solution2(String s) {
    int n = s.length;
    int maxLength = 0;
    Map<String, int> charMap = Map<String, int>();
    int left = 0;

    for (int right = 0; right < n; right++) {
      if (!charMap.containsKey(s[right]) || charMap[s[right]]! < left) {
        charMap[s[right]] = right;
        maxLength = max(maxLength, right - left + 1);
      } else {
        left = charMap[s[right]]! + 1;
        charMap[s[right]] = right;
      }
    }

    return maxLength;
  }

  // Solution 3: Integer Array
  int solution3(String s) {
    int n = s.length;
    int maxLength = 0;
    List<int> charIndex = List<int>.filled(128, -1);
    int left = 0;

    for (int right = 0; right < n; right++) {
      if (charIndex[s.codeUnitAt(right)] >= left) {
        left = charIndex[s.codeUnitAt(right)] + 1;
      }
      charIndex[s.codeUnitAt(right)] = right;
      maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
  }
}
