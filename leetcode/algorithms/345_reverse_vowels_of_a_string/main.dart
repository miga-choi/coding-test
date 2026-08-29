class ReverseVowelsOfAString {
  /**
   * Two Pointers
   *
   * Complexities:
   *   N - The size of `s`
   *   - Time Complexities: O(N)
   *   - Space Complexities: O(N)
   */
  String reverseVowels(String s) {
    List<String> sArray = s.split("");
    int i = 0;
    int j = sArray.length - 1;

    while (i < j) {
      if ("AEIOUaeiou".contains(sArray[i])) {
        while (true) {
          if ("AEIOUaeiou".contains(sArray[j])) {
            String temp = sArray[i];
            sArray[i] = sArray[j];
            sArray[j] = temp;
            j--;
            break;
          }
          j--;
        }
      }
      i++;
    }

    return sArray.join("");
  }


  // Solution
  /**
   * Solution 1
   * 
   * Two Pointers
   *
   * Complexities:
   *   N - The size of `s`
   *   - Time Complexities: O(N)
   *   - Space Complexities: O(N)
   */
  static const _vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

  String solution1(String s) {
    final chars = s.split('');
    var left = 0;
    var right = chars.length - 1;

    while (left < right) {
      while (left < right && !_vowels.contains(chars[left])) {
        left++;
      }
      while (left < right && !_vowels.contains(chars[right])) {
        right--;
      }

      if (left < right) {
        final tmp = chars[left];
        chars[left] = chars[right];
        chars[right] = tmp;
        left++;
        right--;
      }
    }

    return chars.join();
  }

  /**
   * Solution 2
   * 
   * Two Pointers + Unicode
   *
   * Complexities:
   *   N - The size of `s`
   *   - Time Complexities: O(N)
   *   - Space Complexities: O(N)
   */
  static const _vowelCodes = {97, 101, 105, 111, 117, 65, 69, 73, 79, 85};

  String solution2(String s) {
    final codes = List<int>.of(s.codeUnits);
    var left = 0;
    var right = codes.length - 1;

    while (left < right) {
      while (left < right && !_vowelCodes.contains(codes[left])) {
        left++;
      }
      while (left < right && !_vowelCodes.contains(codes[right])) {
        right--;
      }

      if (left < right) {
        final tmp = codes[left];
        codes[left] = codes[right];
        codes[right] = tmp;
        left++;
        right--;
      }
    }

    return String.fromCharCodes(codes);
  }

  /**
   * Solution 3
   * 
   * Two Pointers
   *
   * Complexities:
   *   N - The size of `s`
   *   - Time Complexities: O(N)
   *   - Space Complexities: O(N)
   */
  String solution3(String s) {
    const vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    final chars = s.split('');
    final idx = <int>[];

    for (var i = 0; i < chars.length; i++) {
      if (vowels.contains(chars[i])) idx.add(i);
    }

    for (var i = 0, j = idx.length - 1; i < j; i++, j--) {
      final tmp = chars[idx[i]];
      chars[idx[i]] = chars[idx[j]];
      chars[idx[j]] = tmp;
    }

    return chars.join();
  }
}
