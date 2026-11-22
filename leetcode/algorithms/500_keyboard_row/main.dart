class KeyboardRow {
  /**
   * Row Lookup Table + First-Letter Row Check
   *
   * Complexities:
   *   i - Length of iᵗʰ Word in `words`
   *   - Time Complexity: O(Σ lenᵢ²)
   *   - Space Complexity: O(1)
   */
  List<String> findWords(List<String> words) {
    const List<int> alphabetNumRow = <int>[2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3];

    final List<String> result = List<String>.empty(growable: true);

    for (String word in words) {
      int row = alphabetNumRow[word.toLowerCase().codeUnits.first - 'a'.codeUnits.first];

      for (int i = 0; i < word.toLowerCase().codeUnits.length; i++) {
        if (alphabetNumRow[word.toLowerCase().codeUnits[i] - 'a'.codeUnits.first] == row) {
          if (i == word.toLowerCase().codeUnits.length - 1) {
            result.add(word);
          }
        } else {
          break;
        }
      }
    }

    return result;
  }


  // Solution
  /**
   * Solution 1
   *
   * Row Lookup Table
   *
   * Complexities:
   *   n - Sum of The Number of Characters in `words`
   *   - Time Complexity: O(n)
   *   - Space Complexity: O(1)
   */
  static const _rows = ['qwertyuiop', 'asdfghjkl', 'zxcvbnm'];
  static final List<int> _rowOf = _buildTable();

  static List<int> _buildTable() {
    final table = List<int>.filled(26, 0);

    for (var r = 0; r < _rows.length; r++) {
      for (final c in _rows[r].codeUnits) {
        table[c - 97] = r;
      }
    }

    return table;
  }

  bool _isOneRow1(String word) {
    final codes = word.codeUnits;
    final row = _rowOf[(codes[0] | 32) - 97];

    for (final c in codes) {
      if (_rowOf[(c | 32) - 97] != row) {
        return false;
      }
    }

    return true;
  }

  List<String> solution1(List<String> words) => [ for (final w in words) if (_isOneRow1(w)) w ];

  /**
   * Solution 2
   *
   * Row Lookup Table
   *
   * Complexities:
   *   n - Sum of The Number of Characters in `words`
   *   - Time Complexity: O(n)
   *   - Space Complexity: O(1)
   */
  static final List<int> _rowBit = () {
    const rows = ['qwertyuiop', 'asdfghjkl', 'zxcvbnm'];
    final bits = List<int>.filled(26, 0);

    for (var r = 0; r < rows.length; r++) {
      for (final c in rows[r].codeUnits) {
        bits[c - 97] = 1 << r;
      }
    }

    return bits;
  }();

  List<String> solution2(List<String> words) {
    final res = <String>[];

    for (final w in words) {
      var mask = 7;

      for (final c in w.codeUnits) {
        mask &= _rowBit[(c | 32) - 97];
        if (mask == 0) {
          break;
        }
      }

      if (mask != 0) {
        res.add(w);
      }
    }

    return res;
  }

  /**
   * Solution 3
   *
   * Regular Expression
   *
   * Complexities:
   *   n - Sum of The Number of Characters in `words`
   *   - Time Complexity: O(n)
   *   - Space Complexity: O(1)
   */
  static final _oneRow3 = RegExp(r'^(?:[qwertyuiop]+|[asdfghjkl]+|[zxcvbnm]+)$', caseSensitive: false);

  List<String> solution3(List<String> words) => words.where(_oneRow3.hasMatch).toList();
}
