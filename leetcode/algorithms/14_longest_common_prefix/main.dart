class LongestCommonPrefix {
  String longestCommonPrefix(List<String> strs) {
    String result = "";

    for (int i = 0; i < strs[0].length; i++) {
      String c = strs[0][i];
      int count = 0;
      for (String str in strs) {
        if (i > str.length - 1 || str[i] != c) {
          return result;
        }
        count++;
        if (count == strs.length) {
          result += c;
        }
      }
    }

    return result;
  }


  // Solution
  String solution(List<String> strs) {
    String commonPrefix = strs.first;
    for (final word in strs) {
      while (!word.startsWith(commonPrefix)) {
        commonPrefix = commonPrefix.substring(0, commonPrefix.length - 1);
      }
    }
    return commonPrefix;
  }
}
