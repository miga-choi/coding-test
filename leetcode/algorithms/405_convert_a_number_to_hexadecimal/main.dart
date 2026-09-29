import 'dart:math';

class ConvertANumberToHexadecimal {
  /**
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  String toHex(int num) {
    String hex = "0123456789abcdef";
    String result = "";

    if (num < 0) {
      // num = num.toUnsigned(32);
      num += pow(2, 32).toInt();
    }

    while (true) {
      result = hex[num % 16] + result;
      num >>= 4;
      if (num == 0) {
        break;
      }
    }

    return result;
  }


  // Solution
  /**
   * Solution 1
   *
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  String solution1(int num) {
    if (num == 0) {
      return '0';
    }

    const digits = '0123456789abcdef';
    var n = num & 0xFFFFFFFF;

    final buf = List<String>.filled(8, '');
    var i = 8;

    while (n != 0) {
      buf[--i] = digits[n & 15];
      n >>= 4;
    }

    return buf.sublist(i).join();
  }

  /**
   * Solution 2
   *
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  String solution2(int num) {
    if (num == 0) {
      return '0';
    }

    const digits = '0123456789abcdef';
    var n = num & 0xFFFFFFFF;

    final codes = List<int>.filled(8, 0);
    var i = 8;
    while (n != 0) {
      codes[--i] = digits.codeUnitAt(n & 15);
      n >>= 4;
    }

    return String.fromCharCodes(codes, i);
  }

  /**
   * Solution 3
   * 
   * Built-in Function
   *
   * Complexities:
   *   - Time Complexity: O(1)
   *   - Space Complexity: O(1)
   */
  String solution3(int num) {
    return (num & 0xFFFFFFFF).toRadixString(16);
  }
}
