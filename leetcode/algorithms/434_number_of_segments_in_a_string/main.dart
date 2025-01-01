class NumberOfSegmentsInAString {
  int countSegments(String s) {
    List<String> sArray = s.split("");
    sArray.removeWhere((v) => v.trim().isNotEmpty);
    return sArray.length;
  }

  // Best Solution
  int bestSolution(String s) {
    List<String> segments = s.trim().split(' ');
    int count = 0;

    if (s.isEmpty) {
      return 0;
    }

    for (int i = 0; i < segments.length; i++) {
      if (segments[i].isNotEmpty) {
        count++;
      }
    }

    return count;
  }
}
