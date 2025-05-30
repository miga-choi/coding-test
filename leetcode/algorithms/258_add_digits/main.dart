class AddDigits {
  int addDigits(int num) {
    int sum = num;
    while (sum >= 10) {
      sum = 0;
      while (num > 0) {
        sum += num % 10;
        num = (num / 10).floor();
      }
      num = sum;
    }
    return sum;
  }


  // Solution
  // Solution 1
  int solution1(int num) {
    int temp = 0;
    while (num > 0) {
      temp = temp + num % 10;
      num = num ~/ 10;

      if (num == 0 && temp > 9) {
        num = temp;
        temp = 0;
      }
    }
    return temp;
  }

  // Solution 2
  int solution2(int num) {
    return num == 0 ? 0 : 1 + (num - 1) % 9;
  }
}
