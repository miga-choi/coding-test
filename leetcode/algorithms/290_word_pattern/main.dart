class WordPattern {
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
  // Solution 1
  bool solution1(String pattern, String s) {
    var list = s.split(' ');
    if (pattern.length != list.length) {
      return false;
    }

    var mapK = {};
    var mapV = {};

    for (int i = 0; i < list.length; i++) {
      var key = pattern[i];
      var value = list[i];

      if (mapK.containsKey(key) || mapV.containsKey(value)) {
        if (mapK[key] != value) return false;
        if (mapV[value] != key) return false;
      } else {
        mapK[key] = value;
        mapV[value] = key;
      }
    }
    return true;
  }

  // Solution 2
  bool solution2(String pattern, String s) {
    // Split the string `s` into individual words and store them in a list
    List<String> words = s.split(" ");

    // Create a dictionary to store the pattern-to-word mappings
    Map<String, String> patternType = {};

    // Boolean variable to store the result
    bool res = false;

    // If the length of the pattern is not equal to the number of words, return false
    if (pattern.length != words.length) {
      return false;
    }

    // Iterate through each character in the pattern and its corresponding word
    for (int i = 0; i < pattern.length; i++) {
      // Check if the character is not already in the dictionary and the word is not already mapped
      if (!patternType.containsKey(pattern[i]) &&
          !patternType.containsValue(words[i])) {
        // Add the character-word pair to the dictionary
        patternType.addEntries({pattern[i]: words[i]}.entries);
      }

      // Check if the current pattern character maps to the current word
      if (patternType[pattern[i]] == words[i]) {
        // If the mapping is correct, set the result to true
        res = true;
      } else {
        // If the mapping is incorrect, set the result to false and break the loop
        res = false;
        break;
      }
    }

    // Return the final result
    return res;
  }
}
