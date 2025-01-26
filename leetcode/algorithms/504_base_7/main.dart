class Base7 {
  String convertToBase7(int num) {
    if (num == 0) {
      return "0";
    }

    int n = num < 0 ? num * -1 : num;

    String result = "";

    while (n > 0) {
      result = "${n % 7}$result";
      n ~/= 7;
    }

    return num < 0 ? "-$result" : result;
  }

  // Solution
  String solution(int num) {
    return num.toRadixString(7);
  }
}
