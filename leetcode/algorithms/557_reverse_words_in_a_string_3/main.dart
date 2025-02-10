class ReverseWordsInAStringIII {
  String reverseWords(String s) {
    List<String> sArray = s.split(" ");

    for (int i = 0; i < sArray.length; i++) {
      sArray[i] = sArray[i].split("").reversed.join();
    }

    return sArray.join(" ");
  }

  // Solution
  String solution(String s) {
    return s.split(' ').map((e) => e.split('').reversed.join()).join(' ');
  }
}
