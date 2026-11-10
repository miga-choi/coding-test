class LicenseKeyFormatting {
  /**
   * Reverse Traversal
   * 
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  String licenseKeyFormatting(String s, int k) {
    String result = "";
    List<String> sArray = s.replaceAll("-", "").split("");

    for (int i = 1; i <= sArray.length; i++) {
      if (i < sArray.length && (i % k) == 0) {
        result = "-${sArray[sArray.length - i].toUpperCase()}$result";
      } else {
        result = "${sArray[sArray.length - i].toUpperCase()}$result";
      }
    }

    return result;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Reverse Traversal
   * 
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  String solution1(String s, int k) {
    const dash = 45;
    final codes = s.codeUnits;

    var count = 0;
    for (final c in codes) {
      if (c != dash) {
        count++;
      }
    }

    if (count == 0) {
      return '';
    }

    final out = List<int>.filled(count + (count - 1) ~/ k, 0);
    var p = out.length;
    var inGroup = 0;

    for (var i = codes.length - 1; i >= 0; i--) {
      final c = codes[i];

      if (c == dash) {
        continue;
      }

      if (inGroup == k) {
        out[--p] = dash;
        inGroup = 0;
      }

      out[--p] = (c >= 97 && c <= 122) ? c - 32 : c;
      inGroup++;
    }

    return String.fromCharCodes(out);
  }

  /**
   * Solution 2
   * 
   * Forward Traversal with First Group Offset
   * 
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  String solution2(String s, int k) {
    const dash = 45;
    final codes = s.codeUnits;

    var count = 0;
    for (final c in codes) {
      if (c != dash) {
        count++;
      }
    }

    if (count == 0) {
      return '';
    }

    var groupSize = count % k == 0 ? k : count % k;
    var inGroup = 0;
    final sb = StringBuffer();

    for (final c in codes) {
      if (c == dash) {
        continue;
      }

      if (inGroup == groupSize) {
        sb.writeCharCode(dash);
        inGroup = 0;
        groupSize = k;
      }

      sb.writeCharCode((c >= 97 && c <= 122) ? c - 32 : c);
      inGroup++;
    }

    return sb.toString();
  }

  /**
   * Solution 3
   * 
   * Cleanup + Chunking
   * 
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  String solution3(String s, int k) {
    final t = s.replaceAll('-', '').toUpperCase();
    if (t.isEmpty) {
      return '';
    }

    final first = t.length % k == 0 ? k : t.length % k;
    final parts = <String>[t.substring(0, first)];

    for (var i = first; i < t.length; i += k) {
      parts.add(t.substring(i, i + k));
    }

    return parts.join('-');
  }
}
