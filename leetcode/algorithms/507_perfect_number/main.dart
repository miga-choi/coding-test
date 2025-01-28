class PerfectNumber {
  bool checkPerfectNumber(int num) {
    int sum = 0;
    for (int i = 1; i < num / 2; i++) {
      if (num % i == 0) {
        sum += i;
      }
    }
    return sum * 2 == num;
  }

  // Solution
  bool solution(int num) {
    int sum = 0;
    for (int i = 1; i * i <= num; i++) {
      if (num % i == 0) {
        sum += i;
        if (i * i != num) {
          sum += num ~/ i;
        }
      }
    }
    return sum - num == num;
  }
}
