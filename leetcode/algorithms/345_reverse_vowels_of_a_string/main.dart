class ReverseVowelsOfAString {
  String reverseVowels(String s) {
    List<String> sArray = s.split("");
    int i = 0;
    int j = sArray.length - 1;

    while (i < j) {
      if ("AEIOUaeiou".contains(sArray[i])) {
        while (true) {
          if ("AEIOUaeiou".contains(sArray[j])) {
            String temp = sArray[i];
            sArray[i] = sArray[j];
            sArray[j] = temp;
            j--;
            break;
          }
          j--;
        }
      }
      i++;
    }

    return sArray.join("");
  }

  // Best Solution
  String bestSolution(String s) {
    List<String> word = s.split('');
    int start = 0;
    int end = s.length - 1;
    String vowels = "aeiouAEIOU";

    while (start < end) {
      while (start < end && !vowels.contains(word[start])) {
        start++;
      }
      while (start < end && !vowels.contains(word[end])) {
        end--;
      }

      String temp = word[start];
      word[start] = word[end];
      word[end] = temp;

      start++;
      end--;
    }

    return word.join('');
  }
}
