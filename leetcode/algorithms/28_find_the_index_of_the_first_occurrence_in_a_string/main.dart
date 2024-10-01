class FindTheIndexOfTheFirstOccurrenceInAString {
  int strStr(String haystack, String needle) {
    return haystack.indexOf(needle);
  }

  // Best Solution
  int bestSolution(String haystack, String needle) {
    if (needle.isEmpty || haystack.isEmpty || needle.length > haystack.length)
      return -1;

    for (int i = 0; i <= haystack.length - needle.length; i++) {
      final String substring = haystack.substring(i, i + needle.length);
      if (substring == needle) {
        return i;
      }
    }
    return -1;
  }
}
