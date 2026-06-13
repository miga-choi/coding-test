class RemoveLinkedListElements {
  /**
   * Complexities:
   *   N - Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  bool isIsomorphic(String s, String t) {
    Map<String, int> sMap = Map<String, int>();
    Map<String, int> tMap = Map<String, int>();

    for (var i = 0; i < s.length; i++) {
      if (sMap[s[i]] == null && tMap[t[i]] == null) {
        sMap[s[i]] = i;
        tMap[t[i]] = i;
      } else if (sMap[s[i]] != null && tMap[t[i]] != null) {
        if (sMap[s[i]] != tMap[t[i]]) {
          return false;
        }
      } else {
        return false;
      }
    }

    return true;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Complexities:
   *   N - Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  bool solution1(String s, String t) {
    if (s.length != t.length) {
      return false;
    }

    Map<String, String> mapST = {};
    Map<String, String> mapTS = {};

    for (int i = 0; i < s.length; i++) {
      String charS = s[i];
      String charT = t[i];

      if (mapST.containsKey(charS)) {
        if (mapST[charS] != charT) {
          return false;
        }
      } else {
        mapST[charS] = charT;
      }

      if (mapTS.containsKey(charT)) {
        if (mapTS[charT] != charS) {
          return false;
        }
      } else {
        mapTS[charT] = charS;
      }
    }

    return true;
  }

  /**
   * Solution 2
   * 
   * Complexities:
   *   N - Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  bool solution2(String s, String t) {
    if (s.length != t.length) {
      return false;
    }

    List<int> mapS = List.filled(256, 0);
    List<int> mapT = List.filled(256, 0);

    for (int i = 0; i < s.length; i++) {
      int codeS = s.codeUnitAt(i);
      int codeT = t.codeUnitAt(i);

      if (mapS[codeS] != mapT[codeT]) {
        return false;
      }

      mapS[codeS] = i + 1;
      mapT[codeT] = i + 1;
    }

    return true;
  }
}
