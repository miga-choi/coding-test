class BaseballGame {
  int calPoints(List<String> operations) {
    List<int> scoreArray = List.empty(growable: true);

    for (String operation in operations) {
      if (operation == "+") {
        scoreArray.add(scoreArray[scoreArray.length - 2] + scoreArray.last);
      } else if (operation == "D") {
        scoreArray.add(scoreArray.last * 2);
      } else if (operation == "C") {
        scoreArray.removeLast();
      } else {
        scoreArray.add(int.parse(operation));
      }
    }

    return scoreArray.isEmpty
        ? 0
        : scoreArray.reduce(
          (int accumulator, int currentValue) => accumulator + currentValue,
        );
  }


  // Solution
  int solution(List<String> operations) {
    int sum = 0;
    List<int> scores = <int>[];

    for (String operation in operations) {
      if (operation == 'C') {
        scores.removeLast();
      } else if (operation == 'D') {
        scores.add(scores.last * 2);
      } else if (operation == '+') {
        scores.add(scores[scores.length - 1] + scores[scores.length - 2]);
      } else {
        scores.add(int.parse(operation));
      }
    }

    for (int score in scores) {
      sum += score;
    }

    return sum;
  }
}
