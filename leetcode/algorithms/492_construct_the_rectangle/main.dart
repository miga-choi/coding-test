import 'dart:math';

class ConstructTheRectangle {
  List<int> constructRectangle(int area) {
    for (int i = sqrt(area).toInt(); i > 0; i--) {
      if (area % i == 0) {
        return [area ~/ i, i];
      }
    }
    return [area, 1];
  }

  // Best Solution
  List<int> bestSolution(int area) {
    int w = sqrt(area).toInt();
    while (area % w != 0) {
      w--;
    }
    return [area ~/ w, w];
  }
}
