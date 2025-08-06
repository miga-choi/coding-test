class RestoreTheArrayFromAdjacentPairs {
  /**
   * Graph & Hash Map & Vector
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
  List<int> restoreArray(List<List<int>> adjacentPairs) {
    Map<int, List<int>> adjacentMap = Map();

    for (List<int> adjacentPair in adjacentPairs) {
      if (!adjacentMap.containsKey(adjacentPair.first)) {
        adjacentMap[adjacentPair.first] = List.empty(growable: true);
      }
      if (!adjacentMap.containsKey(adjacentPair.last)) {
        adjacentMap[adjacentPair.last] = List.empty(growable: true);
      }

      adjacentMap[adjacentPair.first]!.add(adjacentPair.last);
      adjacentMap[adjacentPair.last]!.add(adjacentPair.first);
    }

    int start = 0;
    for (MapEntry element in adjacentMap.entries) {
      if (element.value.length == 1) {
        start = element.key;
        break;
      }
    }

    int length = adjacentPairs.length + 1;
    List<int> result = List.empty(growable: true);
    int curr = start;
    int prev = -100001;

    for (int i = 0; i < length; i++) {
      result.add(curr);

      List<int> neighbors = adjacentMap[curr]!;

      int next;
      if (neighbors.length == 1 || neighbors.first != prev) {
        next = neighbors.first;
      } else {
        next = neighbors.last;
      }

      prev = curr;
      curr = next;
    }

    return result;
  }
}
