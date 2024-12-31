import 'dart:math';

class AddStrings {
  String addStrings(String num1, String num2) {
    String num = "";

    List<String> num1Array = num1.split("");
    List<String> num2Array = num2.split("");

    int num1Length = num1Array.length;
    int num2Length = num2Array.length;
    int numLength = max(num1Length, num2Length);

    int up = 0;

    for (int i = 1; i <= numLength; i++) {
      int _num1 = num1Length - i >= 0 ? int.parse(num1Array[num1Length - i]) : 0;
      int _num2 = num2Length - i >= 0 ? int.parse(num2Array[num2Length - i]) : 0;
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

  // Best Solution 1
  String bestSolution(String num1, String num2) {
    final StringBuffer sb = StringBuffer();

    int i = num1.length - 1;
    int j = num2.length - 1;
    int carry = 0;

    while (i >= 0 || j >= 0) {
      int sum = carry;

      if (i >= 0) {
        sum += (num1.codeUnitAt(i--) - '0'.codeUnitAt(0));
      }
      if (j >= 0) {
        sum += (num2.codeUnitAt(j--) - '0'.codeUnitAt(0));
      }

      sb.write(sum % 10);
      carry = sum ~/ 10;
    }

    if (carry != 0) {
      sb.write(carry);
    }
    return sb.toString().split('').reversed.join();
  }

  // Best Solution 2
  String bestSolution2(String num1, String num2) {
    int carry = 0;
    int i = num1.length - 1;
    int j = num2.length - 1;
    String ans = "";

    String addString(String s1, String s2, int i, int j, int c, String ans) {
      if (c == 0 && i < 0 && j < 0) {
        return ans.split('').reversed.join();
      }

      if (i >= 0) {
        c += int.parse(s1[i]);
        i--;
      }

      if (j >= 0) {
        c += int.parse(s2[j]);
        j--;
      }

      ans += String.fromCharCode(c % 10 + '0'.codeUnitAt(0));
      c = c ~/ 10;

      return addString(s1, s2, i, j, c, ans);
    }

    return addString(num1, num2, i, j, carry, ans);
  }
}
