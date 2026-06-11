class IsomorphicStrings {
  /**
   * Complexities:
   *   N - Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  public boolean isIsomorphic(String s, String t) {
    if (s.length() != t.length()) {
      return false;
    }

    int[] sMap = new int[50000];
    int[] tMap = new int[50000];

    for (int i = 0; i < s.length(); i++) {
      if (sMap[s.charAt(i)] != tMap[t.charAt(i)]) {
        return false;
      }
      sMap[s.charAt(i)] = i + 1;
      tMap[t.charAt(i)] = i + 1;
    }

    return true;
  }


  // Solution
  /**
   * Complexities:
   *   N - Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  public boolean solution(String s, String t) {
    int[] mapS = new int[256];
    int[] mapT = new int[256];

    int length = s.length();

    for (int i = 0; i < length; i++) {
      char charS = s.charAt(i);
      char charT = t.charAt(i);

      if (mapS[charS] != mapT[charT]) {
        return false;
      }

      mapS[charS] = i + 1;
      mapT[charT] = i + 1;
    }

    return true;
  }
}
