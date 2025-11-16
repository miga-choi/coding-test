class GroupAnagrams {
  /**
   * Complexities:
   *   N - size of strs
   *   K - max size of strings in strs
   *   - Time Complexity: O(N * K * logᴷ)
   *   - Space Complexity: O(N * K)
   */
  List<List<String>> groupAnagrams(List<String> strs) {
    Map<String, List<String>> strMap = Map();

    for (final String str in strs) {
      List<String> srtArray = str.split("");
      srtArray.sort();
      String sortedStr = srtArray.join();

      if (!strMap.containsKey(sortedStr)) {
        strMap[sortedStr] = List.empty(growable: true);
      }

      strMap[sortedStr]!.add(str);
    }

    return strMap.values.toList();
  }


  // Solution
  /**
   * Solution 1
   * 
   * Sorted String as Key
   * 
   * Complexities:
   *   N - size of strs
   *   K - max size of strings in strs
   *   - Time Complexity: O(N * K * logᴷ)
   *   - Space Complexity: O(N * K)
   */
  List<List<String>> solution1(List<String> strs) {
    Map<String, List<String>> anagramGroups = {};

    for (final s in strs) {
      List<String> chars = s.split('');
      chars.sort();
      String sortedKey = chars.join('');

      anagramGroups.update(
        sortedKey,
        (value) => value..add(s),
        ifAbsent: () => [s],
      );
    }

    return anagramGroups.values.toList();
  }

  /**
   * Solution 2
   * 
   * Character Count as Key
   * 
   * Complexities:
   *   N - size of strs
   *   K - max size of strings in strs
   *   - Time Complexity: O(N * K)
   *   - Space Complexity: O(N * K)
   */
  List<List<String>> solution2(List<String> strs) {
    Map<String, List<String>> anagramGroups = {};
    final int aCode = 'a'.codeUnitAt(0);

    for (final s in strs) {
      List<int> counts = List.filled(26, 0);
      for (int i = 0; i < s.length; i++) {
        counts[s.codeUnitAt(i) - aCode]++;
      }

      String countKey = counts.join('#');

      anagramGroups.update(
        countKey,
        (value) => value..add(s),
        ifAbsent: () => [s],
      );
    }

    return anagramGroups.values.toList();
  }
}
