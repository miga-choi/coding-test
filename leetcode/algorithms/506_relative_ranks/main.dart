import 'dart:math';

class RelativeRanks {
  List<String> findRelativeRanks(List<int> score) {
    List<String> result = List<String>.filled(score.length, "");

    List<int> sortedScore = List<int>.from(score);
    sortedScore.sort((int p, int n) => n - p);

    for (int i = 0; i < score.length; i++) {
      if (score[i] == sortedScore.first) {
        result[i] = "Gold Medal";
      } else if (score[i] == sortedScore[1]) {
        result[i] = "Silver Medal";
      } else if (score[i] == sortedScore[2]) {
        result[i] = "Bronze Medal";
      } else {
        result[i] = "${sortedScore.indexOf(score[i]) + 1}";
      }
    }

    return result;
  }

  // Solution
  List<String> solution(List<int> score) {
    // Convert the list of scores to a map where the key is the index and the value is the score
    Map<int, int> map = score.asMap();

    // Initialize an empty list to store the ranks
    List<String> ans = List.generate(score.length, (_) => '');

    // Define the medals
    final medals = ["Gold Medal", "Silver Medal", "Bronze Medal"];

    // Sort the entries of the map in descending order of the scores
    final entries = map.entries.toList()
      ..sort((a, b) => b.value.compareTo(a.value));

    // Assign the medals to the top three scores
    for (int i = 0; i < min(3, score.length); i++) {
      final key = entries[i].key;
      ans[key] = medals[i];
    }

    // Assign the placement number as the rank for the rest of the scores
    for (int i = 3; i < score.length; i++) {
      final key = entries[i].key;
      ans[key] = "${i + 1}";
    }

    // Return the list of ranks
    return ans;
  }
}
