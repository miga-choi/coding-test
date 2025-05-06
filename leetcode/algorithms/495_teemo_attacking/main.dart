class TeemoAttacking {
  int findPoisonedDuration(List<int> timeSeries, int duration) {
    int total = 0;

    for (var i = 1; i < timeSeries.length; i++) {
      if (timeSeries[i] > timeSeries[i - 1] + duration) {
        total += duration;
      } else {
        total += timeSeries[i] - timeSeries[i - 1];
      }
    }

    return total + duration;
  }


  // Solution
  int solution(List<int> timeSeries, int duration) {
    int out = duration;

    for (int i = 1; i < timeSeries.length; i++) {
      out += timeSeries[i] - timeSeries[i - 1] > duration ? duration : timeSeries[i] - timeSeries[i - 1];
    }

    return out;
  }
}
