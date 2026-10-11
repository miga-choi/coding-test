import 'dart:math';

class AddStrings {
  /**
   * Complexities:
   *   N - The Size of `num1`
   *   M - The Size of `num2`
   *   - Time Complexity: O(max(N, M))
   *   - Space Complexity: O(1)
   */
  String addStrings(String num1, String num2) {
    String num = "";

    List<String> num1Array = num1.split("");
    List<String> num2Array = num2.split("");

    int num1Length = num1Array.length;
    int num2Length = num2Array.length;
    int numLength = max(num1Length, num2Length);

    int up = 0;

    for (int i = 1; i <= numLength; i++) {
      int _num1 = num1Length - i >= 0
          ? int.parse(num1Array[num1Length - i])
          : 0;
      int _num2 = num2Length - i >= 0
          ? int.parse(num2Array[num2Length - i])
          : 0;
      int _num = _num1 + _num2 + up;

      if (_num > 9) {
        _num -= 10;
        up = 1;
      } else {
        up = 0;
      }

      num = _num.toString() + num;
    }

    return up > 0 ? "1" + num : num;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Two Pointers
   *
   * Complexities:
   *   N - The Size of `num1`
   *   M - The Size of `num2`
   *   - Time Complexity: O(max(N, M))
   *   - Space Complexity: O(1)
   */
  String solution1(String num1, String num2) {
    const zero = 48;
    final a = num1.codeUnits;
    final b = num2.codeUnits;

    var i = a.length - 1;
    var j = b.length - 1;
    var carry = 0;

    final buf = List<int>.filled(
      (a.length > b.length ? a.length : b.length) + 1,
      0,
    );
    var k = buf.length;

    while (i >= 0 || j >= 0 || carry != 0) {
      final x = i >= 0 ? a[i--] - zero : 0;
      final y = j >= 0 ? b[j--] - zero : 0;
      final sum = x + y + carry;
      buf[--k] = zero + sum % 10;
      carry = sum ~/ 10;
    }

    return String.fromCharCodes(buf, k);
  }

  /**
   * Solution 2
   * 
   * StringBuffer + Reverse
   *
   * Complexities:
   *   N - The Size of `num1`
   *   M - The Size of `num2`
   *   - Time Complexity: O(max(N, M))
   *   - Space Complexity: O(1)
   */
  String solution2(String num1, String num2) {
    final sb = StringBuffer();
    var i = num1.length - 1, j = num2.length - 1, carry = 0;

    while (i >= 0 || j >= 0 || carry != 0) {
      final x = i >= 0 ? num1.codeUnitAt(i--) - 48 : 0;
      final y = j >= 0 ? num2.codeUnitAt(j--) - 48 : 0;
      final sum = x + y + carry;
      sb.write(sum % 10);
      carry = sum ~/ 10;
    }

    return sb.toString().split('').reversed.join();
  }
}
