class LetterCombinationsOfAPhoneNumber {
  /**
   * Recursion: Backtracking (DFS)
   * - Time Complexity: O(4ᴺ)
   * - Space Complexity: O(N)
   */
  List<String> letterCombinations(String digits) {
    Map<String, String> lettersMap = {
      "2": "abc",
      "3": "def",
      "4": "ghi",
      "5": "jkl",
      "6": "mno",
      "7": "pqrs",
      "8": "tuv",
      "9": "wxyz",
    };

    List<String> result = [];
    List<String> row = [];

    void backtracking(final int index) {
      if (index == digits.length) {
        result.add(row.join(""));
        return;
      }

      String letters = lettersMap[digits[index]]!;
      for (int i = 0; i < letters.length; i++) {
        row.add(letters[i]);
        backtracking(index + 1);
        row.removeLast();
      }
    }

    backtracking(0);

    return result;
  }


  // Solution
  /**
   * Recursion: Backtracking (DFS)
   * - Time Complexity: O(4ᴺ)
   * - Space Complexity: O(N)
   */
  final Map<String, String> phoneMap = {
    '2': 'abc',
    '3': 'def',
    '4': 'ghi',
    '5': 'jkl',
    '6': 'mno',
    '7': 'pqrs',
    '8': 'tuv',
    '9': 'wxyz',
  };

  void _backtrack(int index, String currentCombination, String digits, List<String> result) {
    if (index == digits.length) {
      result.add(currentCombination);
      return;
    }

    String letters = phoneMap[digits[index]]!;

    for (int i = 0; i < letters.length; i++) {
      _backtrack(index + 1, currentCombination + letters[i], digits, result);
    }
  }

  List<String> solution(String digits) {
    if (digits.isEmpty) {
      return [];
    }

    List<String> result = [];

    _backtrack(0, "", digits, result);

    return result;
  }
}
