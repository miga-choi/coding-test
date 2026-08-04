class WordPattern {
  /**
   * Complexities:
   *   N - The size of `pattern`
   *   M - The size of `s`
   *   - Time Complexity: O(N * M)
   *   - Space Complexity: O(N + M)
   */
  bool wordPattern(String pattern, String s) {
    Map<String, String> patternMap = Map<String, String>();
    List<String> patternArray = pattern.split("");
    List<String> sArray = s.split(" ");

    if (patternArray.length != sArray.length) {
      return false;
    }

    for (int i = 0; i < patternArray.length; i++) {
      if (patternMap[patternArray[i]] == null) {
        if (patternMap.containsValue(sArray[i])) {
          return false;
        }
        patternMap[patternArray[i]] = sArray[i];
      } else {
        if (sArray[i] != patternMap[patternArray[i]]) {
          return false;
        }
      }
    }

    return true;
  }


  // Solution
  /**
   * Bijective Hash Maps
   * 
   * Complexities:
   *   N - The size of `pattern`
   *   M - The number of characters' length in `s`
   *   - Time Complexity: O(N + M)
   *   - Space Complexity: O(N + M)
   */
  bool solution(String pattern, String s) {
    List<String> words = s.split(' ');

    if (pattern.length != words.length) {
      return false;
    }

    Map<String, String> charToWord = {};
    Map<String, String> wordToChar = {};

    for (int i = 0; i < pattern.length; i++) {
      String char = pattern[i];
      String word = words[i];

      if (charToWord.containsKey(char)) {
        if (charToWord[char] != word) {
          return false;
        }
      } else {
        charToWord[char] = word;
      }

      if (wordToChar.containsKey(word)) {
        if (wordToChar[word] != char) {
          return false;
        }
      } else {
        wordToChar[word] = char;
      }
    }

    return true;
  }
}
