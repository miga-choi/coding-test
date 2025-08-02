class DestinationCity {
  /**
   * Set
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
  String destCity(List<List<String>> paths) {
    Set<String> cities = Set<String>();

    for (List<String> path in paths) {
      cities.add(path[0]);
    }

    for (List<String> path in paths) {
      final String destination = path[1];
      if (!cities.contains(destination)) {
        return destination;
      }
    }

    return "";
  }
}
