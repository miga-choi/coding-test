class IntegerToRoman {
  /**
   * Greedy
   *
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  String intToRoman(int num) {
    const List<int> numbers = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
    const List<String> characters = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"];

    String result = "";

    for (int i = 0; ; i++) {
      while (num >= numbers[i]) {
        num -= numbers[i];
        result += characters[i];
      }
      if (num <= 0) {
        break;
      }
    }

    return result;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Greedy
   *
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  String solution1(int num) {
    const List<int> values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
    const List<String> symbols = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"];

    StringBuffer result = StringBuffer();

    for (int i = 0; i < values.length; i++) {
      while (num >= values[i]) {
        num -= values[i];
        result.write(symbols[i]);
      }
    }

    return result.toString();
  }

  /**
   * Solution 2
   *
   * Hard Coding
   *
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  String solution2(int num) {
    const List<String> thousands = ["", "M", "MM", "MMM"];
    const List<String> hundreds = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"];
    const List<String> tens = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"];
    const List<String> ones = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"];

    return thousands[num ~/ 1000] + hundreds[(num % 1000) ~/ 100] + tens[(num % 100) ~/ 10] + ones[num % 10];
  }
}
