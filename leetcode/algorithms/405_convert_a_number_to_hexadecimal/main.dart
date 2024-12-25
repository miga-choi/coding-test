import 'dart:math';

class ConvertANumberToHexadecimal {
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
}
