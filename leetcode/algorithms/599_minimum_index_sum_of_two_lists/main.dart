class MinimumIndexSumOfTwoLists {
  List<String> findRestaurant(List<String> list1, List<String> list2) {
    List<String> result = List<String>.empty(growable: true);
    Map<String, int> stringNumMap = Map<String, int>();
    int minIndex = list1.length + list2.length;

    for (int i = 0; i < list1.length; i++) {
      int index = list2.indexOf(list1[i]);
      if (index >= 0) {
        stringNumMap[list1[i]] = i + index;
        if (i + index < minIndex) {
          minIndex = i + index;
        }
      }
    }

    for (int i = 0; i < list1.length; i++) {
      if (stringNumMap[list1[i]] == minIndex) {
        result.add(list1[i]);
      }
    }

    return result;
  }

  // Solution
  List<String> solution(List<String> list1, List<String> list2) {
    List<String> result = [];
    int? least;

    for (int i = 0; i < list1.length; i++) {
      for (int j = 0; j < list2.length; j++) {
        if (list1[i] == list2[j]) {
          if (result.isEmpty) {
            result.add(list1[i]);
            least = i + j;
          } else if (i + j < least!) {
            result.clear();
            result.add(list1[i]);
            least = i + j;
          } else if (i + j == least) {
            result.add(list1[i]);
          }
        }
      }
    }

    return result;
  }
}
