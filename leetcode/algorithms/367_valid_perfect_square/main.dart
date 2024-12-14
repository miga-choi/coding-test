class ValidPerfectSquare {
  bool isPerfectSquare(int num) {
    if (num > 1) {
      for (int i = 0; i < num; i++) {
        if (i * i > num) {
          return false;
        } else if (i * i == num) {
          break;
        }
      }
    }
    return true;
  }

  // Best Solution
  bool bestSolution(int num) {
    for (int i = 1; i <= num; i++) {
      if (i * i == num.abs()) {
        return true;
      }
    }
    return false;
  }
}
