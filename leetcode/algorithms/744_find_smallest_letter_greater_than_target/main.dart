class FindSmallestLetterGreaterThanTarget {
  String nextGreatestLetter(List<String> letters, String target) {
    if (letters.last.codeUnitAt(0) <= target.codeUnitAt(0)) {
      return letters.first;
    }

    for (int i = 0; i < letters.length; i++) {
      if (letters[i].codeUnitAt(0) > target.codeUnitAt(0)) {
        return letters[i];
      }
    }

    return letters.first;
  }


  // Solution
  String solution(List<String> letters, String target) {
    int start = 0;
    int end = letters.length - 1;

    while (start <= end) {
      int mid = start + (end - start) ~/ 2;

      if (letters[mid].compareTo(target) > 0) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }

    // If start is out of bounds, wrap around to the first element.
    return start < letters.length ? letters[start] : letters[0];
  }
}
