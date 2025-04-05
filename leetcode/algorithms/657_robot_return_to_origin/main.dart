class RobotReturnToOrigin {
  bool judgeCircle(String moves) {
    int landscape = 0;
    int portrait = 0;

    for (String c in moves.split("")) {
      switch (c) {
        case 'U':
          portrait++;
          break;
        case 'D':
          portrait--;
          break;
        case 'R':
          landscape++;
          break;
        case 'L':
          landscape--;
          break;
      }
    }

    return landscape == 0 && portrait == 0;
  }
}
