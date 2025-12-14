class RomanToInteger {
  /**
   * HashMap
   *
   * Complexities:
   *   N - Length of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int romanToInt(String s) {
    Map<String, int> romanMap = Map<String, int>();
    romanMap["I"] = 1;
    romanMap["V"] = 5;
    romanMap["X"] = 10;
    romanMap["L"] = 50;
    romanMap["C"] = 100;
    romanMap["D"] = 500;
    romanMap["M"] = 1000;

    s = s
        .replaceAll("CM", "DCCCC")
        .replaceAll("CD", "CCCC")
        .replaceAll("XC", "LXXXX")
        .replaceAll("XL", "XXXX")
        .replaceAll("IX", "VIIII")
        .replaceAll("IV", "IIII");

    int result = 0;
    for (String c in s.split("")) {
      result += romanMap[c] ?? 0;
    }

    return result;
  }


  // Solution
  /**
   * Solution 1
   * 
   * HashMap & Look-ahead
   *
   * Complexities:
   *   N - Length of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution1(String s) {
    final Map<String, int> romanMap = {
      'I': 1,
      'V': 5,
      'X': 10,
      'L': 50,
      'C': 100,
      'D': 500,
      'M': 1000,
    };

    int total = 0;
    int n = s.length;

    for (int i = 0; i < n; i++) {
      int currentValue = romanMap[s[i]]!;

      int nextValue = (i + 1 < n) ? romanMap[s[i + 1]]! : 0;

      if (currentValue < nextValue) {
        total -= currentValue;
      } else {
        total += currentValue;
      }
    }

    return total;
  }

  /**
   * Solution 2
   *
   * Complexities:
   *   N - Length of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution2(String s) {
    int total = 0;
    int prevValue = 0;

    for (int i = s.length - 1; i >= 0; i--) {
      int currentValue = _getValue(s[i]);

      if (currentValue < prevValue) {
        total -= currentValue;
      } else {
        total += currentValue;
      }

      prevValue = currentValue;
    }

    return total;
  }

  int _getValue(String char) {
    switch (char) {
      case 'I':
        return 1;
      case 'V':
        return 5;
      case 'X':
        return 10;
      case 'L':
        return 50;
      case 'C':
        return 100;
      case 'D':
        return 500;
      case 'M':
        return 1000;
      default:
        return 0;
    }
  }
}
